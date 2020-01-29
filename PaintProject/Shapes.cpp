#include "Shapes.h"

void Shapes::setColor(COLORREF color)
{
	bgColor = color;
}

int Shapes::minX()
{
	return xBegin > xEnd ? xEnd : xBegin;
}

int Shapes::maxX()
{
	return xBegin>xEnd ? xBegin : xEnd;
}

int Shapes::minY()
{
	return yBegin>yEnd ? yEnd : yBegin;
}

int Shapes::maxY()
{
	return yBegin>yEnd ? yBegin : yEnd;
}

CPoint Shapes::lastPoint()
{
	CPoint point(0, 0);
	return point;
}

