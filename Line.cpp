#include "Line.h"
#include <iostream>
#include <cmath>

// LINE : VECTOR

 // Default constructor
Line::Line() : Vector() {}
// Copy constructor
Line::Line(const Line& rhs) : Vector(rhs) 
{
	a = rhs.a;
	b = rhs.b;
}
// Parameterized Constructor p1,p2
Line::Line(const Point& a, const Point& b) : a(a), b(b) {}
// Operator =
Line& Line::operator=(const Line& rhs)
{
	if (this != &rhs)
	{
		a = rhs.a;
		b = rhs.b;
	}
	return *this;
}

//SET&GET
void Line::setA(Point& a)
{
	this->a = a;
}
void Line::setB(Point& b)
{
	this->b = b;
}
Point Line::getA()const
{
	return a;
}
Point Line::getB()const
{
	return b;
}


// Line Direction - vector parallel to line
Vector Line::LineDirection()const
{
	//a point 1 b point 2
	return Vector(b.getX() - a.getX(), b.getY() - a.getY(), b.getZ() - a.getZ());
}

// Normal vector - vector perpendicullar to line
Vector Line::NormalVector()
{
	double x = b.getX() - a.getX(); //x2-x1 = x of vector, last-first
	double y = b.getY() - a.getY();
	return Vector(-y, x, 0);
}

// Angle between 2 lines - angle in radians
double Line::LineAngle(const Line& rhs)const
{
	//1. Dot product of 2 vectors
	double dot = (a.getX() * b.getX()) + (a.getY() * b.getY()) + (a.getZ() * b.getZ());

	//2. |l1|=sqrt((x)2+(y)2+(z)2 ) |l2|=sqrt((x)2+(y)2+(z)2 )
	double v1 = sqrt(pow(a.getX(), 2) + pow(a.getY(), 2) + pow(a.getZ(), 2));
	double v2 = sqrt(pow(b.getX(), 2) + pow(b.getY(), 2) + pow(b.getZ(), 2));

	//3. Angle = cos = dot / |l1|*|l2|
	double angle = acos(dot / (v1 * v2));
	return angle;
}

// OPERATORS

// Check if a point lies on a line (+)
bool Line:: operator+(const Point& rhs)const
{
	double x = (rhs.getX() - a.getX()) / (b.getX() - a.getX());
	double y = (rhs.getY() - a.getY()) / (b.getY() - a.getY());
	double z = (rhs.getZ() - a.getZ()) / (b.getZ() - a.getZ());
	return x == y == z;
}

// Check if line is parallel to another line with operator ||
bool Line:: operator||(const Line& rhs)const
{
	double x1 = rhs.a.getX() - a.getX();
	double x2 = rhs.b.getX() - b.getX();

	double y1 = rhs.a.getY() - a.getY();
	double y2 = rhs.b.getY() - b.getY();

	double z1 = rhs.a.getZ() - a.getZ();
	double z2 = rhs.b.getZ() - b.getZ();

	return (x1 == x2 && y1 == y2 && z1 == z2 && x1 == y1 && y1 == z1);
}

// Check if lines are equal with operator ==
bool Line:: operator==(const Line& rhs) const
{
	// текущия Line а с новия Line
	return (((*this) + rhs.a) && ((*this) + rhs.b));
}

// Check if line cross another line with operator && 
bool Line:: operator&&(const Line& rhs)const
{
	Vector v1(a, b);
	Vector v2(rhs.a, rhs.b);
	double x = v1.getX() / v2.getX();
	double y = v1.getY() / v2.getY();
	double z = v1.getZ() / v2.getZ();
	return x != y && x != z && y != z;
}

// Check if Skew lines with operator != 
bool Line:: operator!=(const Line& rhs) const
{
	return !(rhs == *this) && !(rhs || *this);
}

// Check if lines are perpendicullar with operator |
bool Line:: operator|(const Line& rhs)const
{
	Vector l1(a, b);
	Vector l2(rhs.a, rhs.b);
	return l1.CheckPerpendicular(l2);
}