#pragma once
#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Line.h"

// class Triangle inherits class Point
class Triangle : public Point
{
public:
	Triangle(); // Default constructor
	Triangle(const Point&, const Point&, const Point&); // Parameterized constructor
	Triangle(const Triangle&); // Copy constructor
	Triangle& operator=(const Triangle&); // Operator =
	~Triangle(); // Destructor

	void TriangleType()const; // Determine type of Triangle
	double TriangleArea()const; // Calculate Triangle area
	double TrianglePerimeter()const; // Calculate Triangle perimeter
	Point TriangleMedicenter()const; // Determine Triangle medicenter

	friend bool operator<(const Point&, const Triangle&); // Operator < if Point lies onand inside Triangle
	friend bool operator>(const Point&, const Triangle&); // Operator > if Point lies on and outside Triangle
	bool operator==(const Point&); // Operator == if Point is on one of the sides of Triangle

public:
	Point A;
	Point B;
	Point C;
	Vector v1;
	Vector v2;
	Vector v3;
};

std::istream& operator>>(std::istream&, Triangle&);
