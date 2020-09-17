#include "Point.h"
#include <iostream>

Point::Point() :x(0.0), y(0.0), z(0.0) {} // Default constructor

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {} // Parameterized constructor

Point::Point(const Point& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {} // Copy Constructor

 // Operator =
Point& Point::operator=(const Point& rhs) 
{
	if (this != &rhs) 
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
	}
	return *this;
}

Point::~Point() {} // Destructor

bool Point::operator==(const Point& rhs)const // Operator ==
{
	return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z);
}

//SET
void Point::setX(double x)
{
	this->x = x;
}
void Point::setY(double y)
{
	this->y = y;
}
void Point::setZ(double z)
{
	this->z = z;
}

//GET
double Point::getX()const 
{
	return x;
}
double Point::getY()const 
{
	return y;
}
double Point::getZ()const 
{
	return z;
}

//PRINT
void Point::print()const 
{
	std::cout << "The point is (" << x << "," << y << "," << z << ").\n";
}

// COUT
std::ostream& operator<<(std::ostream& out,	const Point& rhs) 
{
	out << rhs.getX() << ", " << rhs.getY() << ", " << rhs.getZ();
	return out;
}

// CIN
std::istream& operator>>(std::istream& in, Point& rhs)
{
	double x, y, z;
	std::cout << "Please enter x: ";
	in >> x;
	std::cout << "Please enter y: ";
	in >> y;
	std::cout << "Please enter z: ";
	in >> z;

	rhs.setX(x);
	rhs.setY(y);
	rhs.setZ(z);

	return in;
}