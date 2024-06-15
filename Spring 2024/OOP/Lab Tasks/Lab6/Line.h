#pragma once
#include "Point.h"
class Line
{
	Point P1;
	Point P2;

public:

	Line(Point& p1, Point& p2);

	Line(int x1, int y1, int x2, int y2);

	Point getP1();

	Point getP2();

	double getSlope();

	void displayLine();
};

