#pragma once
#include "Graf.h"
#include <memory>

class CProgramm1Dlg : public CDialogEx
{
public:
	CProgramm1Dlg(CWnd* pParent = nullptr);
	virtual ~CProgramm1Dlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRAMM1_DIALOG };
#endif
	DECLARE_MESSAGE_MAP()

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	afx_msg void  OnClose();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBnClickedCircle();
	afx_msg void OnBnClickedSquare();
	afx_msg void OnBnClickedRectangle();
	afx_msg void OnBnClickedTringle();

	CMyView* m_view;
};
