// libmbedtls.h : main header file for the libmbedtls DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// ClibmbedtlsApp
// See libmbedtls.cpp for the implementation of this class
//

class ClibmbedtlsApp : public CWinApp
{
public:
	ClibmbedtlsApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
