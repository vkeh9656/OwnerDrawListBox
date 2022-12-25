
// OwnerDrawListBoxDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "OwnerDrawListBox.h"
#include "OwnerDrawListBoxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COwnerDrawListBoxDlg 대화 상자



COwnerDrawListBoxDlg::COwnerDrawListBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OWNERDRAWLISTBOX_DIALOG, pParent), m_list_box_bk_brush(RGB(0, 0, 128))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COwnerDrawListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATA_LIST, m_data_list);
}

BEGIN_MESSAGE_MAP(COwnerDrawListBoxDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DRAWITEM()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// COwnerDrawListBoxDlg 메시지 처리기

BOOL COwnerDrawListBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	CString str;
	for (int i = 0; i < 10; i++)
	{
		str.Format(L"item - %d", i);
		m_data_list.InsertString(i, str);
	}

	m_data_list.SetItemHeight(0, 25);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void COwnerDrawListBoxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR COwnerDrawListBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COwnerDrawListBoxDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDS)
{
	if (nIDCtl == IDC_DATA_LIST)
		if (lpDS->itemID != 0xFFFFFFFF && lpDS->itemID < m_data_list.GetCount())
		{
			if ((lpDS->itemAction & ODA_DRAWENTIRE) ||
				(lpDS->itemAction & ODA_FOCUS) ||
				(lpDS->itemAction & ODA_SELECT))
			{
				CDC* p_dc = CDC::FromHandle(lpDS->hDC);

				if (lpDS->itemState & ODS_SELECTED)
				{
					if (lpDS->itemState & ODS_FOCUS)
					{
						p_dc->FillSolidRect(&lpDS->rcItem, RGB(0, 200, 255));
					}
					else
					{
						p_dc->FillSolidRect(&lpDS->rcItem, RGB(0, 100, 255));
					}
					p_dc->SetTextColor(RGB(255, 255, 0));
				}
				else
				{
					p_dc->FillSolidRect(&lpDS->rcItem, RGB(0, 0, 128));
					p_dc->SetTextColor(RGB(128, 128, 128));
				}

				CString str;
				m_data_list.GetText(lpDS->itemID, str);
				p_dc->TextOut(lpDS->rcItem.left + 5, lpDS->rcItem.top + 5, str);
			}
		}
	
	else CDialogEx::OnDrawItem(nIDCtl, lpDS);
}


HBRUSH COwnerDrawListBoxDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr;
		
	if (pWnd != NULL && pWnd->m_hWnd == m_data_list.m_hWnd) // 새로 그리는 핸들이 같을 경우
	{
		hbr = m_list_box_bk_brush;
	}
	else hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	return hbr;
}
