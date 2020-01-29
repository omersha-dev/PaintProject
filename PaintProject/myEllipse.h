#pragma once
#include "Shapes.h"
#include "stdafx.h"

class myEllipse : public Shapes {
public:
	myEllipse() ;
	myEllipse(int xBegin, int yBegin, int xEnd, int yEnd) : Shapes(xBegin, yBegin, xEnd, yEnd) { style = 2; }
	myEllipse(int xBegin, int yBegin, int xEnd, int yEnd,int fill, int thin, COLORREF color) : Shapes(xBegin, yBegin, xEnd, yEnd,fill, thin, color) { style = 2; }

	void Draw(CDC *dc);
	bool isExist(CPoint point);
};