// SPcontrols.cpp : main source file for SPcontrols.exe
//

#include "stdafx.h"

#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>

#include <atlmisc.h>

#define _WTL_CE_NO_ZOOMSCROLL
#include <atlce.h>

#include "resource.h"
#include "maindlg.h"

CAppModule _Module;

LPCTSTR CMainDlg::m_szAppKey = L"Software\\WTL\\SPcontrols";

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int nCmdShow)
{

	HRESULT hRes = CMainDlg::ActivatePreviousInstance(hInstance, lpstrCmdLine, true);
	
	if(FAILED(hRes) || S_FALSE == hRes)
	{
		return hRes;
	}

	hRes = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	ATLASSERT(SUCCEEDED(hRes));

	AtlInitCommonControls(ICC_UPDOWN_CLASS);
	SHInitExtraControls();

	hRes = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	int nRet = CMainDlg::DlgAppRun(lpstrCmdLine, nCmdShow);

	_Module.Term();
	::CoUninitialize();

	return nRet;
}

