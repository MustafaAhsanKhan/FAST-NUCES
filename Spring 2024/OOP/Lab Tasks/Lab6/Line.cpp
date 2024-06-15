#include "Line.h"
#include <iostream>
using namespace std;

Line::Line(Point& p1, Point& p2)
{
	P1 = p1;
	P2 = p2;
}

Line::Line(int x1, int y1, int x2, int y2)
{
	P1.setx(x1);
	P1.sety(y1);

	P2.setx(x2);
	P2.sety(y2);
}

Point Line::getP1()
{
	return P1;
}

Point Line::getP2()
{
	return P2;
}

double Line::getSlope()
{
	double slope;
	slope = double((P2.gety() - P1.gety())) / double((P2.getx() - P1.getx()));

	return slope;
}

void Line::displayLine()
{
	P1.display();
	cout << endl;
	P2.display();
}