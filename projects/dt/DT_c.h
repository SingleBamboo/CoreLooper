#ifndef _DEBUG_TRACE_2004
#define _DEBUG_TRACE_2004

#include <Windows.h>

#define DEBUG_TRACE
//ֻ��release�²���Ҳ������DEBUG_TRACE�������������ļ�
#ifndef _DEBUG
	#define	DEBUG_TRACE_FILE
#endif

#ifdef DEBUG_TRACE
typedef int BOOL;
	BOOL DebugTrace(char* lpszFormat,...);
	#define DT	DebugTrace
	#define _DT DEBUG_TRACE
#else
	#define DT
	#undef _DT
#endif


#endif
