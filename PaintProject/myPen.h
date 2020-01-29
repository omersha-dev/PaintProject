#pragma once
#include <vector>
#include "myLine.h"
#include "stdafx.h"

class myPen : public myLine {
public:
	myPen();
	myPen(int xBegin, int yBegin);
	myPen(int xBegin, int yBegin, int thin, COLORREF color);
	CPoint lastPoint();
	void Build(CPoint currentPoint);
	void Draw(CDC *dc);
	bool isExist(CPoint point);

protected:
	vector <CPoint> ArrOfPoints;
};

/*class MyPen :public MyLine {
public:
	MyPen();
	MyPen(int x1, int y1)
		:MyLine(x1, y1, x1, y1)
	{
		CPoint p(x1, y1);
		pArr.push_back(p);
		style = 5;
	}
	MyPen(int x1, int y1, int thin, COLORREF color)
		:MyLine(x1, y1, x1, y1, thin, color)
	{
		CPoint p(x1, y1);
		pArr.push_back(p);
		style = 5;
	}
	CPoint lastP()
	{

		return pArr[pArr.size() - 1];
	}
	void Build(CPoint cur)
	{
		pArr.push_back(cur);
	}
	void Draw(CDC *dc)
	{
		CPen myPen(PS_SOLID, isThin ? 1 : 4, bgColor);
		for (int i = 1; i<pArr.size(); i++)
		{
			dc->SelectObject(myPen);
			dc->MoveTo(pArr[i - 1]);
			dc->LineTo(pArr[i]);
		}
	}
	bool isExist(CPoint p)
	{
		return 0;
	}
protected:
	vector <CPoint> ArrOfPoints;
};*/