
// MyCalc.h: PROJECT_NAME uygulaması için ana üst bilgi dosyası
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH için bu dosyayı eklemeden önce 'pch.h' öğesini ekle"
#endif

#include "resource.h"		// ana semboller


// CMyCalcApp:
// Bu sınıfın uygulaması için bkz. MyCalc.cpp
//

class CMyCalcApp : public CWinApp
{
public:
	CMyCalcApp();

// Geçersiz Kılar
public:
	virtual BOOL InitInstance();

// Uygulama

	DECLARE_MESSAGE_MAP()
};

extern CMyCalcApp theApp;
