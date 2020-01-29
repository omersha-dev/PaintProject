#pragma once
#include "Shapes.h"
#include "stdafx.h"

class myLine : public Shapes {
public:
	myLine();
	myLine(int xBegin, int yBegin, int xEnd, int yEnd) : Shapes(xBegin, yBegin, xEnd, yEnd) { style = 1; }
	myLine(int xBegin, int yBegin, int xEnd, int yEnd, int thin, COLORREF color) : Shapes(xBegin, yBegin, xEnd, yEnd,0,thin, color) { style = 1; }
	void Draw(CDC *dc);
	bool isExist(CPoint point);
};