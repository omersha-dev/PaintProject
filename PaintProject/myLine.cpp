#include "myLine.h"

void myLine::Draw(CDC * dc)
{
	CPen myPen(PS_SOLID, isThin ? 1 : 5, bgColor);
	dc->SelectObject(&myPen);
	dc->MoveTo(xBegin, yBegin);
	dc->LineTo(xEnd, yEnd);
}

bool myLine::isExist(CPoint point)
{
	int xx = xBegin - xEnd, yy = yBegin - yEnd;
	int xMin = minX(), xMax = maxX(), yMin = minY(), yMax = maxY();
	double m = (double)yy / (double)xx;

	if ((point.y - yBegin - m * (point.x - xBegin))>-7
		&& (point.y - yBegin - m * (point.x - xBegin)<7)
		&& (!(point.x < xMin ||
			point.x > xMax ||
			point.y < yMin ||
			point.y > yMax)))
		return 1;
	return 0;
}
