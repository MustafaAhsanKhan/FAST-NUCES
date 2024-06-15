#include "Line.h"
#include <cmath>

Line::Line() : P1(1, 5) , P2(10, 15) {}

Line::Line(int x1, int y1, int x2, int y2) : P1(x1, y1) , P2(x2, y2) {}

Line::Line(const Point& p1, const Point& p2) : P1(p1), P2(p2) {}

float Line::findSlope()
{
	return (float(P2.getY_Coordinate() - P1.getY_Coordinate()) / float(P2.getX_Coordinate() - P1.getX_Coordinate()));
}

float Line::findLength()
{
	return sqrt(pow(P2.getX_Coordinate() - P1.getX_Coordinate(), 2) + pow(P2.getY_Coordinate() - P1.getY_Coordinate(), 2));
}

Point& Line::findMidPoint()
{
	int x_coord;
	int y_coord;

	x_coord = (P1.getX_Coordinate() + P2.getX_Coordinate()) / 2;
	y_coord = (P1.getY_Coordinate() + P2.getY_Coordinate()) / 2;
	Point MP(x_coord, y_coord);

	return MP;
}