﻿#pragma once
namespace Bear {
namespace Core
{

//XiongWanPing 2011.01.17
//ByteBuffer用来管理行缓冲,具有如下特点:
//.可以指定最大行缓冲长度
//.保证有效数据是连续的
class CORE_EXPORT ByteBuffer
{
	DISABLE_COPY_CLASS(ByteBuffer);
public:
	ByteBuffer(void);
	virtual ~ByteBuffer(void);
	void SetName(const char *name)
	{
		mName = name;
	}

	int Append(const ByteBuffer& src, bool makeSureEndNull = true);

	//指定缓冲初始和最大尺寸
	int SetBufferSize(UINT nInitSize = 32, UINT nMaxSize = 512 * 1024);
	int PrepareBuf(UINT minSize, bool zero = false);

	int MakeSureEndWithNull();
	bool IsEndWithNull();

	void SetUserData(DWORD dwUserData)
	{
		m_dwUserData = dwUserData;
	}

	DWORD GetUserData()const
	{
		return m_dwUserData;
	}

	// **************************************************************
	// Description: 移动数据到首地址
	// Parameters : 
	// Return	  : 成功返回0
	// Author	  : XiongWanPing
	// Date		  : 2011-01-19
	// Notice	  : 调用本函数来保证内部缓冲有最大的连续可写空闲空间
	// **************************************************************
	void MoveToHead()
	{
		if (m_pBuf && m_nDataOff > 0)
		{
			if (m_nData > 0)
			{
				memmove(m_pBuf, m_pBuf + m_nDataOff, m_nData);
			}
			else
			{
				ASSERT(FALSE);
			}

			m_nDataOff = 0;
		}
	}

	//返回最大还可写入的字节数
	int GetMaxWritableBytes(bool reservedEndNull = true)
	{
		int bytes = GetActualDataLength();
		int ret = m_cbMaxBuf - bytes;
		if (reservedEndNull)
		{
			--ret;//-1是为'\0'保留一个字节
		}

		if (ret < 0)
		{
			ret = 0;
		}
		return ret;
	}

	//返回当前空闲字节数
	int GetFreeSize()
	{
		if (m_cbBuf >= m_nData)
		{
			return m_cbBuf - m_nData;
		}

		ASSERT(FALSE);
		return 0;
	}

	//返回当前尾部的空闲字数
	//一般与GetNewDataPointer()配合使用
	int GetTailFreeSize()
	{
		if (m_cbBuf >= m_nDataOff + m_nData)
		{
			return m_cbBuf - m_nDataOff - m_nData;
		}

		ASSERT(FALSE);
		return 0;
	}

	int GetBufferSize()const
	{
		return m_cbBuf;
	}

	//返回写入时新数据的buffer首地址,供直接写数据时使用
	LPBYTE GetNewDataPointer()
	{
		return GetDataPointer() + GetActualDataLength();
	}


	//返回数据指针
	LPBYTE GetDataPointer()const;

	//返回有效数据的字节数
	int GetActualDataLength()const
	{
		return m_nData;
	}

	int GetDataLength()const
	{
		return m_nData;
	}

	// **************************************************************
	// Description: 空写指定的字节数
	// Parameters : 
	// Return	  : 成功返回0
	// Author	  : XiongWanPing
	// Date		  : 2011-01-19
	// Notice	  : 为减少一次memcpy,有时调用者直接向ByteBuffer的buf写数据
	//				此场景下，由调用者保证ByteBuffer buf的有效性:
	//				一般事先调用MoveToHead()保证ByteBuffer的有效数据位于缓冲最开头
	//				再调用GetFreeSize()得到最大可写字节数,
	//				写入数据后再调用WriteDirect()来通知ByteBuffer增加有效字节数
	// **************************************************************
	int WriteDirect(int nInc)
	{
		if (m_nDataOff + m_nData + nInc <= m_cbBuf)
		{
			m_nData += nInc;
			return 0;
		}

		ASSERT(FALSE);
		return -1;
	}

	BOOL IsInited()
	{
		return m_pBuf != NULL;
	}

	//返回缓冲是否为空
	bool IsEmpty()const
	{
		return m_nData == 0;
	}

	//清除有效数据
	void clear()
	{
		m_nDataOff = 0;
		m_nData = 0;
	}

	bool empty()const
	{
		return IsEmpty();
	}

	void EmptyEx()
	{
		if (m_pBuf)
		{
			delete[]m_pBuf;
			m_pBuf = NULL;
		}
		m_cbBuf = 0;
		m_cbMaxBuf = 0;
		m_nDataOff = 0;
		m_nData = 0;
	}

	int Write(const std::string& str)
	{
		int ret = Write((LPVOID)str.c_str(), (int)str.length());
		//MakeSureEndWithNull();
		return ret;
	}

	int Write(const char* str)
	{
		if (!str || str[0] == 0)
		{
			return 0;
		}

		int ret = Write((LPVOID)str, (int)strlen(str));
		return ret;
	}

	//写入指定的数据到缓存
	int Write(const LPVOID pData, int cbData);

	//写一个字节到缓存
	int WriteByte(BYTE data);

	// **************************************************************
	// Description: 消耗指定字节的数据
	// Parameters : 
	// Return	  : 成功返回0
	// Author	  : XiongWanPing
	// Date		  : 2011-01-17
	// Notice	  : 
	// **************************************************************
	int Eat(int cbEat)
	{
		ASSERT(m_pBuf);

		if (cbEat > m_nData)
		{
			ASSERT(FALSE);
			return -1;
		}

		m_nDataOff += cbEat;
		m_nData -= cbEat;

		if (m_nData == 0)
		{
			//消耗完所有数据时，转到首地址
			m_nDataOff = 0;
			m_pBuf[0] = 0;//清除，可避免解析旧字符串
		}

		return 0;
	}


	// **************************************************************
	// Description: 从尾部开始消耗指定字节的数据
	// Parameters : 
	// Return	  : 成功返回0
	// Author	  : XiongWanPing
	// Date		  : 2011-01-19
	// Notice	  : 
	// **************************************************************
	int ReverseEat(int cbEat)
	{
		if (cbEat < 0)
		{
			ASSERT(FALSE);
			return -1;
		}

		if (m_nData >= cbEat)
		{
			m_nData -= cbEat;

			if (m_nData == 0)
			{
				//消耗完所有数据时，转到首地址
				m_nDataOff = 0;
			}

			return 0;
		}

		//ASSERT(FALSE);
		return -1;
	}


protected:
	LPBYTE	m_pBuf;		//buffer首地址
	int		m_cbBuf;	//当前m_pBuf指向的buffer总字节数
	int		m_cbMaxBuf;	//允许buffer扩展到的最大字节数,m_cbBuf<=m_cbMaxBuf

	int		m_nDataOff;	//有效数据起始偏移
	int		m_nData;	//有效数据字节数

	DWORD	m_dwUserData;//用户自定义数据，默认为0,ByteBuffer不会对其做任何操作

	std::string	mName;//给ByteBuffer加个标记，方便诊断问题
};
}
}