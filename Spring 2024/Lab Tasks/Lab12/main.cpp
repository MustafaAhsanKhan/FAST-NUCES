#include <iostream>
using namespace std;
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#include "Faculty.h"

int main()
{
	// QUESTION 1 //
	Shape* S;
	S = new Circle(5, "Circle");
	S->display();
	S->area();

	S = new Rectangle(5, 10, "Rectangle");
	S->display();
	S->area();

	S = new Triangle(5, 10, "Triangle");
	S->display();
	S->area();

	delete S;

	// QUESTION 2 //

	Faculty F("Professor", "CS", 2, 500, 45, 5, 5, "Dr. Mustafa", "FAST NUCES");

	F.display();



}