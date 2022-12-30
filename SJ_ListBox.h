#pragma once


// SJ_ListBox
// #pragma comment (lib, "SJ_ListBox.lib")

/*
void SJ_ListBox::DrawUserItem(CDC* ap_dc, RECT* ap_rect, int a_index, void* ap_data, unsigned char a_select_flag, unsigned char a_focus_flag)
{
	if (a_select_flag) ap_dc->SetTextColor(RGB(255, 255, 0));

	else ap_dc->SetTextColor(RGB(128, 128, 128));

	CString str;
	GetText(a_index, str);
	ap_dc->TextOut(ap_rect->left + 5, ap_rect->top + 5, str);
} */

class SJ_ListBox : public CListBox
{
	DECLARE_DYNAMIC(SJ_ListBox)
private:
	CBrush m_list_box_bk_brush;
	COLORREF m_select_color, m_focus_color, m_bk_color;
public:
	SJ_ListBox();
	virtual ~SJ_ListBox();

	void SetItemColor(COLORREF a_select_color, COLORREF a_focus_color, COLORREF a_bk_color);
	virtual void DrawListItem(CDC* ap_dc, RECT* ap_rect, int a_index, void* ap_data, unsigned char a_select_flag, unsigned char a_focus_flag);
	virtual void DrawUserItem(CDC* ap_dc, RECT* ap_rect, int a_index, void* ap_data, unsigned char a_select_flag, unsigned char a_focus_flag);

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
};


