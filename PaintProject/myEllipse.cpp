#include "myEllipse.h"

void myEllipse::Draw(CDC * dc)
{
	CBrush myBrush;
	CPen myPen(PS_SOLID, isThin ? 1 : 5, bgColor);
	dc->SelectObject(&myPen);
	if (isFill)
		myBrush.CreateSolidBrush(bgColor);
	else
		myBrush.CreateSolidBrush(RGB(240, 240, 240));
	dc->SelectObject(myBrush);
	dc->Ellipse(xBegin, yBegin, xEnd, yEnd);
}

bool myEllipse::isExist(CPoint point)
{
	if (point.x > xBegin && point.x<xEnd && point.y>yBegin && point.y < yEnd)
		return 1;
	return 0;
}
