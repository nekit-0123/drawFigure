
// Programm1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProgramm1App:
// See Programm1.cpp for the implementation of this class
//

class CProgramm1App : public CWinApp
{
public:
	CProgramm1App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CProgramm1App theApp;
