#pragma once

#include "handler.h"
#include "procnode.h"

namespace Bear {
namespace Core
{
//Ҫͬ��static char levels[] = { '.','.','V','D','I','W','E','A', };
enum
{
	eLogMin = 2,
	eLogV = 2,//��ֵ��android�ϵĶ�Ӧ
	eLogD,
	eLogI,
	eLogW,
	eLogE,
	eLogA,//ASSERT
	eLogMax = eLogA,
};

struct tagObjectLogConfig
{
	tagObjectLogConfig()
	{
		mDumpLevel = eLogI;
		mDumpFileLevel = eLogI;
	}

	int	mDumpLevel;		//�����logcat�еļ���
	int	mDumpFileLevel; //���浽�ļ�
};

struct tagLogItem
{
	int		mLevel;
	std::string	mTag;
	std::string	mText;
	DWORD	mThreadId;
};


#ifdef _MSC_VER
#define vsnprintf _vsnprintf
#endif

#define LOG_IMPL(Tag,logLevel)										\
	do{																\
		int level = logLevel;										\
		string tag=Tag;												\
		tagObjectLogConfig cfg;										\
		HandlerEx::GetLogConfig(tag, cfg);						\
		if (cfg.mDumpFileLevel > level && cfg.mDumpLevel > level)	\
		{															\
			return;													\
		}															\
																	\
		char szMsg[1024 * 64 * sizeof(TCHAR)];						\
		memset(szMsg, 0, sizeof(szMsg));							\
																	\
		va_list argList;											\
		va_start(argList, pszFormat);								\
		vsnprintf(szMsg,sizeof(szMsg)-1, (char*)pszFormat, argList);	\
		va_end(argList);											\
																	\
		HandlerEx::Log(tag,level, cfg, szMsg);					\
	}while(0)

//XiongWanPing 2018.07
//�뾡������Handler��࣬���԰�һЩ���ܴ�Handler�߳�������HandlerEx��,�д������·�����ʵ����Щ����
class CORE_EXPORT HandlerEx :public Handler
	, public IProcDataGetter
	, public IProcDataSetter
{
	SUPER(Handler)
public:
	HandlerEx();

	static void GetLogMap(std::map<std::string, tagObjectLogConfig>& obj);
	static void SetTagConfig(const std::string& tag, int dumpLevel, int dumpFileLevel);
	static void LoadLogConfig(FileSystem::IniFile *ini, const std::string& section);
	static void SaveLogConfig(FileSystem::IniFile *ini, const std::string& section);
	static int GetLogLevel(char ch);

	//flagsΪeProcDataFlag,��|�����־
	template<class T> int BindProcData(T& value, std::string name, std::string desc = "", DWORD flags = PDF_READ)
	{
		ASSERT(IsMyselfThread());

		if (name == CHILD_NODE_NAME)//��Ҫ����
		{
			ASSERT(FALSE);
			return -1;
		}

		if (!mProcNode)
		{
			mProcNode = make_shared<ProcNode>();
		}

		weak_ptr<IProcDataGetter>	getter;
		weak_ptr<IProcDataSetter>	setter;

		if (flags & PDF_GETTER)
		{
			getter = dynamic_pointer_cast<IProcDataGetter>(shared_from_this());
		}

		if (flags & PDF_SETTER)
		{
			setter = dynamic_pointer_cast<IProcDataSetter>(shared_from_this());;
		}

		int ret = mProcNode->Bind(name, value, desc, flags, getter, setter);
		return ret;
	}

	int OnProcDataGetter(const std::string& name, std::string& desc);

	int OnProcDataSetter(std::string name, int value);
	int OnProcDataSetter(std::string name, bool value);
	int OnProcDataSetter(std::string name, BYTE value);
	int OnProcDataSetter(std::string name, std::string value);
	int OnProcDataSetter(std::string name, WORD value);
	int OnProcDataSetter(std::string name, DWORD value);
	int OnProcDataSetter(std::string name, double value);
	int OnProcDataSetter(std::string name, LONGLONG value);
	int OnProcDataSetter(std::string name, ULONGLONG value);

	virtual int Test();
	virtual void DumpProcData(std::string& xml);

	virtual void LogV(const char* pszFormat, ...);
	virtual void LogD(const char* pszFormat, ...);
	virtual void LogI(const char* pszFormat, ...);
	virtual void LogW(const char* pszFormat, ...);
	virtual void LogE(const char* pszFormat, ...);
	static  void Log(const std::string&tag, int level, tagObjectLogConfig& cfg, const char* text);

	static void GetLogConfig(const std::string& objName, tagObjectLogConfig& cfg);

protected:
	LRESULT OnMessage(UINT msg, WPARAM wp, LPARAM lp);

	std::shared_ptr<ProcNode> mProcNode;

	static CriticalSection	mLogConfigCS;
	static std::map<std::string, tagObjectLogConfig> sLogMap;
private:
	HandlerEx & operator=(HandlerEx& src);
	HandlerEx(const HandlerEx&);
};
}
}
