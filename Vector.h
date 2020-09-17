#pragma once
#include "Point.h"
#include <iostream>

// class Vector inherits class Point
class Vector : public Point
{
public:
	Vector(); // Default constructor
	Vector(double, double, double); // Parameterized constructor
	Vector(const Vector&); // Copy Constructor
	Vector(const Point&, const Point&); // Parameterized Constructor p1,p2
	Vector& operator =(const Vector&); // Operator =
	virtual ~Vector(); // Virtual destructor declaration

	// Length of Vector
	double VectorLength()const;
	// Direction of Vector
	Vector DirectionOfVector()const;
	// Zero Vector
	bool CheckZero()const;
	// Parallel Vector
	bool CheckParallel(const Vector&)const;
	// Perendicular Vector
	bool CheckPerpendicular(const Vector&)const;

	// OPERATORS
	Vector operator+(const Vector&)const;
	Vector operator-(const Vector&)const;
	Vector operator*(double)const;
	double operator*(const Vector&)const;
	Vector operator^(const Vector&)const;
	double operator()(const Vector&, const Vector&);

};

// CIN, COUT
std::istream& operator>>(std::istream&, Vector&);
std::ostream& operator<<(std::ostream&, const Vector&);