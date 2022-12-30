#pragma once


// SJ_ListBox

class SJ_ListBox : public CListBox
{
	DECLARE_DYNAMIC(SJ_ListBox)
private:
	CBrush m_list_box_bk_brush;
public:
	SJ_ListBox();
	virtual ~SJ_ListBox();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
};


