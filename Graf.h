#pragma once
#include <GdiPlus.h>
#include "Figure.hpp"

#pragma comment(lib,"GdiPlus.lib")
using namespace Gdiplus;

namespace Figure
{
	enum en_Figure : long
	{
		Circle		= 0,
		Square		= 1,
		Rectangle   = 2,
		Tringle     = 3
	};
};

class CMyView : public CView
{
	DECLARE_DYNCREATE(CMyView)
	DECLARE_MESSAGE_MAP()
public:
	CMyView();
	~CMyView();
	void CreateFigure(Figure::en_Figure data);

protected:
	virtual void OnInitialUpdate();
	virtual void OnDraw(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void DeleteFigure();

	Bitmap* backBuffer;
	CFigure *figure;
};