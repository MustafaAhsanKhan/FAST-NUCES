#include "Point.h"

Point::Point() : X_Coordinate(0), Y_Coordinate(0) {}

Point::Point(int x, int y) : X_Coordinate(x), Y_Coordinate(y) {}

Point::Point(const Point& p) : X_Coordinate(p.X_Coordinate), Y_Coordinate(p.Y_Coordinate) {}

int Point::getX_Coordinate() const
{
	return X_Coordinate;
}

int Point::getY_Coordinate() const
{
	return Y_Coordinate;
}