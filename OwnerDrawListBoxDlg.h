
// OwnerDrawListBoxDlg.h: 헤더 파일
//

#pragma once
#include "SJ_ListBox.h"

class MyListBox : public SJ_ListBox
{
public:
	virtual void DrawUserItem(CDC* ap_dc, RECT* ap_rect, int a_index, void* ap_data, unsigned char a_select_flag, unsigned char a_focus_flag)
	{
		if (a_select_flag) ap_dc->SetTextColor(RGB(255, 255, 0));

		else ap_dc->SetTextColor(RGB(128, 128, 0));

		CString str, temp;
		GetText(a_index, temp);

		str.Format(L"< SJ_ListBox : %02d > %s", a_index + 1, temp);
		ap_dc->TextOut(ap_rect->left + 5, ap_rect->top + 5, str);
	}
};

// COwnerDrawListBoxDlg 대화 상자
class COwnerDrawListBoxDlg : public CDialogEx
{
private:
	MyListBox m_data_list;
// 생성입니다.
public:
	COwnerDrawListBoxDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OWNERDRAWLISTBOX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

};
