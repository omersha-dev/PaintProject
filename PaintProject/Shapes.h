#pragma once
#include "stdafx.h"
#include <vector>
using namespace std;
class Shapes {
public:
	int xBegin, yBegin, xEnd, yEnd, style, isThin,isFill;
	COLORREF bgColor;
	Shapes();
	void setColor(COLORREF color);

	Shapes(int x1, int y1, int x2, int y2) : xBegin(x1), yBegin(y1), xEnd(x2), yEnd(y2) { bgColor = RGB(0, 0, 0); };
	Shapes(int x1, int y1, int x2, int y2, int fill,int thin, int color) : xBegin(x1), yBegin(y1), xEnd(x2), yEnd(y2), isThin(thin),isFill(fill), bgColor(color) {};
	virtual int minX();
	virtual int maxX();
	virtual int minY();
	virtual int maxY();
	virtual void Build(CPoint cur) {}
	virtual CPoint lastPoint();
	virtual void Draw(CDC *dc) = 0;
	virtual bool isExist(CPoint point) = 0;
	virtual ~Shapes(void) {};
};