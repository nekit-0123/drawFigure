#include "stdafx.h"
#include "Graf.h"

IMPLEMENT_DYNCREATE(CMyView, CView)
GdiplusStartupInput gdiplusStartupInput;
ULONG_PTR gdiplusToken;
CMyView::CMyView()
	: figure(nullptr)
	, backBuffer(nullptr)
{}

CMyView::~CMyView()
{
	DeleteFigure();

	if (backBuffer)
	{
		delete backBuffer;
		backBuffer = nullptr;
	}
}

BEGIN_MESSAGE_MAP(CMyView, CView)
	ON_WM_SIZE()
END_MESSAGE_MAP()

void CMyView::OnDraw(CDC* pDC)
{
	CRect rcBounds;
	GetClientRect(rcBounds);
	Graphics graphics(pDC->m_hDC);
	if (backBuffer == NULL)
		backBuffer = new Bitmap(rcBounds.right, rcBounds.bottom, &graphics);
	else 
	{		
		Graphics temp(backBuffer);
		if (figure)
		{
			figure->SetGraphics(&temp);
			figure->Draw();
		}

		graphics.DrawImage(backBuffer, 0, 0, 0, 0, rcBounds.right, rcBounds.bottom, UnitPixel);
	}
}

void CMyView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
}

void CMyView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	OnSize(0, 0, 0);
}

void CMyView::CreateFigure(Figure::en_Figure data)
{
	DeleteFigure();
	switch (data)
	{
		case Figure::en_Figure::Circle:
			figure = new CCircle();
		break;
		case Figure::en_Figure::Square:
			figure = new CSquare();
		break;
		case Figure::en_Figure::Rectangle:
			figure = new CRectangle();
		break;
		case Figure::en_Figure::Tringle:
			figure = new CTringle();
		break;
	}
}

void CMyView::DeleteFigure()
{
	if (figure)
	{
		delete figure;
		figure = nullptr;
	}
}