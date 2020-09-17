#include "Segment.h"
#include <cmath>

// Default constructor
Segment::Segment() : Line()
{
	startP = 0.0;
	endP = 0.0;
}

// Parameterized constructor
Segment::Segment(const Point& a, const Vector& v, const double& s, const double& end)
{
	startP = s;
	endP = end;
	double res = 0;
	res = (startP + endP) / 2;
	xx = a.getX() + v.getX() * res;
	yy = a.getY() + v.getY() * res;
	zz = a.getZ() + v.getZ() * res;
}

// Copy Constructor
Segment::Segment(const Segment& rhs)
{
	startP = rhs.startP;
	endP = rhs.endP;
}

// Operator =
Segment& Segment:: operator=(const Segment& other)
{
	if (this != &other)
	{
		Line::operator=(other);
		startP = other.startP;
		endP = other.endP;
		xx = other.xx;
		yy = other.yy;
		zz = other.zz;
	}
	return *this;
}

//Destructor
Segment::~Segment() 
{
}

// Length of Segment
double Segment::SegmentLength()const
{
	// return Real number (double)
	return sqrt(pow(xx, 2) + pow(yy, 2) + pow(zz, 2));;
}

// Middle of Segment ((xA+xB)/2,(yA+yB)/2,(zA+zB)/2)
Point Segment::SegmentMiddle()const 
{
	// return Point
	return Point((xx) / 2, (yy) / 2, (zz) / 2);
}

// Operator == if Point lies on a Segment
bool Segment::operator==(const Point& p)
{
	if ((p.getX() >= startP && p.getX() <= endP) && (p.getY() >= startP && p.getY() <= endP) && (p.getZ() >= startP && p.getZ() <= endP))
	{
		return true;
	}
	return false;
}