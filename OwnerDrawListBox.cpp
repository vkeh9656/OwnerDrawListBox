
// OwnerDrawListBox.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "OwnerDrawListBox.h"
#include "OwnerDrawListBoxDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COwnerDrawListBoxApp

BEGIN_MESSAGE_MAP(COwnerDrawListBoxApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// COwnerDrawListBoxApp 생성

COwnerDrawListBoxApp::COwnerDrawListBoxApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 COwnerDrawListBoxApp 개체입니다.

COwnerDrawListBoxApp theApp;


// COwnerDrawListBoxApp 초기화

BOOL COwnerDrawListBoxApp::InitInstance()
{
	CWinApp::InitInstance();

	COwnerDrawListBoxDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

