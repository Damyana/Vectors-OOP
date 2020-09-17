#pragma once
#include "Element.h"
#include <iostream>

// class Point inherits class Element
class Point:public Element
{
public:
	Point(); // Default constructor
	Point(double, double, double);  // Parameterized constructor
	Point(const Point&); // Copy Constructor
	Point& operator=(const Point&); // Operator =
	virtual ~Point(); // Virtual destructor declaration

	bool operator==(const Point&)const; // Operator ==

	//SET
	void setX(double);
	void setY(double);
	void setZ(double);

	//GET
	double getX()const;
	double getY()const;
	double getZ()const;

	// Print function
	void print()const;

private:
	double x;
	double y;
	double z;
};

// Cin, Cout operators
std::ostream& operator<<(std::ostream&, const Point&);
std::istream& operator>>(std::istream&, Point&);