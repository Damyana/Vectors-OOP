#pragma once
#include "Line.h"

// class Segment inherits class Line
class Segment : public Line
{
public:
	Segment(); // Default constructor 
	Segment(const Point&, const Vector&, const double&, const double&); // Parameterized constructor
	Segment(const Segment&); // Copy Constructor
	Segment& operator=(const Segment&); // Operator =
	~Segment(); // Destructor

	double SegmentLength()const; // Length of Segment
	Point SegmentMiddle()const; // Middle of Segment
	bool operator==(const Point& p); // Operator == if Point lies on a Segment

private:
	// two Points start and end
	double startP;
	double endP;
	double xx = 0.0, yy = 0.0, zz = 0.0;
};