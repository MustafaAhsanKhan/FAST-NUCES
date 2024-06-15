#pragma once
class Point
{
private:
	int X_Coordinate;
	int Y_Coordinate;

public:
	Point();

	Point(int x, int y);

	Point(const Point& p);

	int getX_Coordinate() const;

	int getY_Coordinate() const;

};

