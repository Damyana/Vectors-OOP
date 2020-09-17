#pragma once
#include "Vector.h"
#include "Point.h"

// class Line inherits class Vector
class Line : public Vector
{
public:
	Line(); // Default constructor
	Line(const Line&);  // Copy Constructor
	Line(const Point&, const Point&);  // Param Constructor p1,p2
	Line& operator=(const Line&); // Operator =
	virtual ~Line() {} // Virtual 

	//SET&GET
	void setA(Point&);
	void setB(Point&);
	Point getA()const;
	Point getB()const;

	// Line Direction - vector parallel to line
	Vector LineDirection()const;
	// Normal vector - vector perpendicullar to line
	Vector NormalVector();
	// Angle between 2 lines - angle in radians
	double LineAngle(const Line&)const;

	//OPERATORS
	bool operator +(const Point&)const; // Check if a point lies on a line (+)
	bool operator ||(const Line&)const; // Check if line is parallel to another line with operator ||
	bool operator ==(const Line& rhs)const; // Check if lines are equal with operator ==
	bool operator &&(const Line&)const; // Check if line cross another line with operator && 
	bool operator !=(const Line&) const; // Check if Skew lines with operator != 
	bool operator |(const Line&)const; // Check if lines are perpendicullar with operator |

private:
	Point a;
	Point b;
	Vector lineDirection;
};
