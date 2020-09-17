#pragma once
#include "Segment.h"
#include "EqualPointException.h"

// class Tetrahedron inherits class Segment
class Tetrahedron : public Segment
{
public:
	Tetrahedron(); // Default constructor
	Tetrahedron(const Point&, const Point&, const Point&, const Point&); // Parameterized constructor
	Tetrahedron(const Tetrahedron&); // Copy constructor
	Tetrahedron& operator=(const Tetrahedron&); // Operator =
	~Tetrahedron(); // Destructor

	bool RegularTetrahedron()const; // Right Tetrahedron - All edges of Tetrahedron are equal
	bool OrthogonalTetrahedron()const;  // Orthogonal Tetrahedron - where every two of opposite edges are perpendicular
	double SurroundingSurface()const; // Surrounding Surface of Tetrahedron
	double TetrahedronVolume()const; // Volume of Tetrahedron

	//OPERATORS
	friend bool operator<(const Point&, const Tetrahedron&); // Operator < if Point lies onand inside Tetrahedron
	friend bool operator>(const Point&, const Tetrahedron&); // Operator > if Point lies on and outside Tetrahedron
	bool operator==(const Point&); // Operator == if Point is on one of the sides of Tetrahedron

public:
	Point A;
	Point B;
	Point C;
	Point D;
};

// COUT & CIN
std::ostream& operator<<(std::ostream&, const Tetrahedron&);
std::istream& operator>>(std::istream&, Tetrahedron&);