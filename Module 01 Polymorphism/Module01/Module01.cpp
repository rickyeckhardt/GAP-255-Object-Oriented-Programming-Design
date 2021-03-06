// Module01.cpp : This file contains the 'main' function
//
// Things to do:
// 1) complete the Shape interface
// 2) complete the implementations for the three specific shape types
// 3) make sure the CalculateArea method is a purely virtual function
// 4) make sure you follow the GAP coding standards
// 
// For extra credit:
// Define a purely virtual method Shape::GetStringRepresentation() which returns an std::string or const char* string formatted as such:
//	Triangle => "Triangle [pt(<x>, <y>), pt(<x>, <y>), pt(<x>, <y>)]"
//	Circle => "Circle [pt(<x>, <y>), radius(<radius>)]"
//	Rectangle => "Rectangle [pt(<x>, <y>), width(<width>), height(<height>)]"
// where <var> should be read as the value of that variable

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include "Defines.h"
#include "Shape.h"

int main()
{
	Shape* pCircle = new Circle(Point(1, 1), 5);
	Shape* pTriangle = new Triangle(Point(1, 1), Point(8, 2), Point(6, 10));
	Shape* pRectangle = new Rectangle(Point(-2, -5), 5, 10);

	// get the areas
	std::cout << "circle    area: " << pCircle->CalculateArea() << std::endl;
	std::cout << "triangle  area: " << pTriangle->CalculateArea() << std::endl;
	std::cout << "rectangle area: " << pRectangle->CalculateArea() << std::endl;

	// clear them
	delete pCircle;
	delete pTriangle;
	delete pRectangle;

	return 0;
}
