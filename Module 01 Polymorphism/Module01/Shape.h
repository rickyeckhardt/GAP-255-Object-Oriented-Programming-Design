#pragma once
#include "Defines.h"

class Shape
{
	// fill this all in
public:
	Shape();
	// virtual destructor
	virtual ~Shape();
	// virtual method
	virtual float CalculateArea() = 0;
};

class Triangle : public Shape
{
protected:
	Point m_point1;
	Point m_point2;
	Point m_point3;

public:
	Triangle(Point p1, Point p2, Point p3)
		: Shape{}
		, m_point1(p1)
		, m_point2(p2)
		, m_point3(p3)
	{
		// empty
	}

	float CalculateArea()
	{
		return abs((m_point1.x * (m_point2.y - m_point3.y) + m_point2.x * (m_point3.y - m_point1.y) + m_point3.x * (m_point1.y - m_point2.y)) / 2);
	}
};

class Rectangle : public Shape
{
protected:
	Point m_topLeftCorner;
	int m_width;
	int m_height;

public:
	Rectangle(Point topLeftCorner, int width, int height)
		: Shape{}
		, m_topLeftCorner(topLeftCorner)
		, m_width(width)
		, m_height(height)
	{
	 // empty
	}

	float CalculateArea()
	{
		return m_width * m_height;
	}
};

class Circle : public Shape
{
protected:
	Point m_center;
	int m_radius;

public:
	Circle(Point center, int radius)
		: Shape {}
		, m_center(center)
		, m_radius(radius)
	{
		// empty
	}
	float CalculateArea()
	{
		return k_PI * m_radius * m_radius;
	}
};

Shape::Shape()
{
 // do any init
}

Shape::~Shape()
{
 // do any cleanup
}