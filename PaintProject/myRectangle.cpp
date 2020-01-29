#include "myRectangle.h"

void myRectangle::Draw(CDC * dc)
{
	CBrush myBrush;
	CPen myPen(PS_SOLID, isThin ? 1 : 5, bgColor);
	dc->SelectObject(&myPen);
	if (isFill)
	myBrush.CreateSolidBrush(bgColor);
	else
	myBrush.CreateSolidBrush(RGB(240, 240, 240));//default color
	dc->SelectObject(myBrush);
	dc->Rectangle(xBegin, yBegin, xEnd, yEnd);
}

bool myRectangle::isExist(CPoint point)
{
	int xMin = minX(), xMax = maxX(), yMin = minY(),yMax =maxY();
	if (!(point.x < xMin || point.x > xMax || point.y < yMin || point.y > yMax))
		return 1;
	return 0;
}
