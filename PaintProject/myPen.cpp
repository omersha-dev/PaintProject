#include "myPen.h"

myPen::myPen(int xBegin, int yBegin) : myLine(xBegin, yBegin, xBegin, yBegin)
{
	CPoint point(xBegin, yBegin);
	ArrOfPoints.push_back(point);

	style = 0;
}

myPen::myPen(int xBegin, int yBegin, int thin, COLORREF color) : myLine(xBegin, yBegin, xBegin, yBegin, thin, color)
{
	CPoint point(xBegin, yBegin);
	ArrOfPoints.push_back(point);
	style = 0;
}

CPoint myPen::lastPoint()
{
	return ArrOfPoints[ArrOfPoints.size() - 1];
}

void myPen::Build(CPoint currentPoint)
{
	ArrOfPoints.push_back(currentPoint);
}

void myPen::Draw(CDC *dc)
{
	CPen myPen(PS_SOLID, isThin ? 1 : 5, bgColor);
	for (int i = 1; i < ArrOfPoints.size(); ++i)
	{
		dc->SelectObject(myPen);
		dc->MoveTo(ArrOfPoints[i - 1]);
		dc->LineTo(ArrOfPoints[i]);
	}
}

bool myPen::isExist(CPoint point)
{
	return 0;
}

