#pragma once
#include "../lab10_project/Point.h"
class Line
{
private:
	Point P1;
	Point P2;

public:
	Line();

	Line(int x1, int y1, int x2, int y2);

	Line(const Point& p1, const Point& p2);

	float findSlope();

	float findLength();

	Point& findMidPoint();
};

