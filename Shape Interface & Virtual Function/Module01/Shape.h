#pragma once
#include "Defines.h"

class Shape
{
	// fill this all in
};

class Triangle : public Shape
{
public:
	Triangle(Point p1, Point p2, Point p3);
	// fill the rest in
};

class Rectangle : public Shape
{
public:
	Rectangle(Point topLeftCorner, int width, int height);
	// fill the rest in
};

class Circle : public Shape
{
public:
	Circle(Point center, int radius);
	// fill the rest in
};