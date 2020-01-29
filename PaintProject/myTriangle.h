#pragma once
#include "Shapes.h"
#include "stdafx.h"

class myTriangle : public Shapes {
public:
	myTriangle();
	myTriangle(int xBegin, int yBegin, int xEnd, int yEnd) : Shapes(xBegin, yBegin, xEnd, yEnd) { style = 3; }
	myTriangle(int xBegin, int yBegin, int xEnd, int yEnd,int fill, int thin, COLORREF color) : Shapes(xBegin, yBegin, xEnd, yEnd,fill, thin, color) { style = 3; }
	void Draw(CDC *dc);
	bool isExist(CPoint point);
};