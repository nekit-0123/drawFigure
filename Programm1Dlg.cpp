#include "stdafx.h"
#include "Programm1.h"
#include "Programm1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CProgramm1Dlg::CProgramm1Dlg(CWnd* pParent)
	: CDialogEx(IDD_PROGRAMM1_DIALOG, pParent)
	, m_view(nullptr)

{}

CProgramm1Dlg::~CProgramm1Dlg()
{}

void CProgramm1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProgramm1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_CREATE()
	ON_BN_CLICKED(ID_CIRCLE, &CProgramm1Dlg::OnBnClickedCircle)
	ON_BN_CLICKED(ID_SQUARE, &CProgramm1Dlg::OnBnClickedSquare)
	ON_BN_CLICKED(ID_RECTANGLE, &CProgramm1Dlg::OnBnClickedRectangle)
	ON_BN_CLICKED(ID_TRINGLE, &CProgramm1Dlg::OnBnClickedTringle)
END_MESSAGE_MAP()


BOOL CProgramm1Dlg::OnInitDialog()
{ 
	CDialogEx::OnInitDialog();
	
	CRect rect;
	GetClientRect(rect);
	rect.top += 30;

	if (m_view != NULL)
	{
		if (m_view->m_hWnd != NULL)
			m_view->MoveWindow(rect);
	}

	return TRUE;
}

int CProgramm1Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_view = new CMyView;
	CCreateContext context;
	context.m_pCurrentFrame = (CFrameWnd*)this;

	m_view->Create(NULL,
		NULL,
		WS_CHILD | WS_VISIBLE,
		CFrameWnd::rectDefault,
		this,
		0,
		&context);
	return 0;
}


void CProgramm1Dlg::OnClose()
{
	OnOK();
}

void CProgramm1Dlg::OnBnClickedCircle()
{
	m_view->CreateFigure(Figure::en_Figure::Circle);
	Invalidate(TRUE);
}

void CProgramm1Dlg::OnBnClickedSquare()
{
	m_view->CreateFigure(Figure::en_Figure::Square);
	Invalidate(TRUE);
}

void CProgramm1Dlg::OnBnClickedRectangle()
{
	m_view->CreateFigure(Figure::en_Figure::Rectangle);
	Invalidate(TRUE);
}

void CProgramm1Dlg::OnBnClickedTringle()
{
	m_view->CreateFigure(Figure::en_Figure::Tringle);
	Invalidate(TRUE);
}
