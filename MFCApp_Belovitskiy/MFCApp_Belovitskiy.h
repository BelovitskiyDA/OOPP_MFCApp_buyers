
// MFCApp_Belovitskiy.h : main header file for the MFCApp_Belovitskiy application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCAppBelovitskiyApp:
// See MFCApp_Belovitskiy.cpp for the implementation of this class
//

class CMFCAppBelovitskiyApp : public CWinApp
{
public:
	CMFCAppBelovitskiyApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCAppBelovitskiyApp theApp;
