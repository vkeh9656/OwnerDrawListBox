// SJ_ListBox.cpp: 구현 파일
//

#include "pch.h"
#include "OwnerDrawListBox.h"
#include "SJ_ListBox.h"


// SJ_ListBox

IMPLEMENT_DYNAMIC(SJ_ListBox, CListBox)

SJ_ListBox::SJ_ListBox() : m_list_box_bk_brush(RGB(0,0,128))
{

}

SJ_ListBox::~SJ_ListBox()
{
}


BEGIN_MESSAGE_MAP(SJ_ListBox, CListBox)
	ON_WM_DRAWITEM_REFLECT()
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()



// SJ_ListBox 메시지 처리기

void SJ_ListBox::DrawItem(LPDRAWITEMSTRUCT lpDS)
{
	if (lpDS->itemID != 0xFFFFFFFF && lpDS->itemID < GetCount())
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
			GetText(lpDS->itemID, str);
			p_dc->TextOut(lpDS->rcItem.left + 5, lpDS->rcItem.top + 5, str);
		}
	}
}


HBRUSH SJ_ListBox::CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/)
{	
	return m_list_box_bk_brush;
}
