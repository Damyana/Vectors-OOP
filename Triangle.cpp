#include <iostream>
#include "Triangle.h"
#include "EqualPointException.h"

// Default constructor
Triangle::Triangle() {}

// Parameterized constructor and use exception
Triangle::Triangle(const Point& a, const Point& b, const Point& c) 
{
	// Exception
	try {
		if (a == b) 
		{
			std::cout << "Point 'a': " << a << " and " << "Point 'b': " << b << std::endl;
			throw EqualPointException();

		}
		else if (a == c) 
		{
			std::cout << "Point 'a': " << a << " and " << "Point 'c': " << c << std::endl;
			throw EqualPointException();
		}
		else if (b == c) 
		{
			std::cout << "Point 'b': " << b << " and " << "Point 'c': " << c << std::endl;
			throw EqualPointException();
		}
		else 
		{
			this->A = a;
			this->B = b;
			this->C = c;
		}

	}
	catch (EqualPointException& e) 
	{
		std::cout << e.what() << std::endl;
	}
}

// Copy constructor
Triangle::Triangle(const Triangle& obj)
{
	A = obj.A;
	B = obj.B;
	C = obj.C;
}

// Operator =
Triangle& Triangle:: operator=(const Triangle& rhs)
{
	if (this != &rhs)
	{
		A = rhs.A;
		B = rhs.B;
		C = rhs.C;
	}
	return *this;
}

// Destructor
Triangle::~Triangle()
{
}

// Determine Triangle type
void Triangle::TriangleType()const 
{

	Vector v1(A, B);
	Vector v2(A, C);
	Vector v3(B, C);

	double A = v1.VectorLength();
	double B = v2.VectorLength();
	double C = v3.VectorLength();

	std::cout << "Type of triangle: ";
	if (A == B == C)
	{
		std::cout << "Equilateral" << std::endl;
	}
	if ((A == B && A != C && B != C) || (A == C && A != B && B != C) || (B == C && A != B && A != C))
	{
		std::cout << "Isosceles" << std::endl;
	}
	else
	{
		std::cout << "Scalene" << std::endl;
	}

	// If a2 + b2 > c2, then it is acute triangle.
	if (pow(A,2)+ pow(B,2) > pow(C,2))
	{
		std::cout << "It's an acute triangle" << std::endl;
	}
	// If a2 + b2 = c2, then it is right triangle.
	if (pow(A, 2) + pow(B, 2) == pow(C, 2))
	{
		std::cout << "It's a right triangle" << std::endl;
	}
	// If a2 + b2 < c2, then it is obtuse triangle.
	if (pow(A, 2) + pow(B, 2) < pow(C, 2))
	{
		std::cout << "It's a obtuse triangle" << std::endl;
	}
}

// Calculate Triangle area
double Triangle::TriangleArea()const
{
	double AC = fabs(sqrt(pow(C.getX() - A.getX(), 2) + (pow(C.getY() - A.getY(), 2)) + (pow(C.getZ() - A.getZ(), 2))));
	std::cout << "ac = " << AC << std::endl;
	double BC = fabs(sqrt(pow(B.getX() - C.getX(), 2) + (pow(B.getY() - C.getY(), 2)) + (pow(B.getZ() - C.getZ(), 2))));
	std::cout << "bc = " << BC << std::endl;
	double AB = fabs(sqrt(pow(A.getX() - B.getX(), 2) + (pow(A.getY() - B.getY(), 2)) + (pow(A.getZ() - B.getZ(), 2))));
	std::cout << "ab = " << AB << std::endl;
	double p = (AC + BC + AB) / 2;
	double area = sqrt((p) * (p - AB) * (p - AC) * (p - BC));
	return area;
}

// Calculate Triangle perimeter
double Triangle::TrianglePerimeter()const 
{
	double AC = fabs(sqrt(pow(C.getX() - A.getX(), 2) + (pow(C.getY() - A.getY(), 2)) + (pow(C.getZ() - A.getZ(), 2))));
	double BC = fabs(sqrt(pow(B.getX() - C.getX(), 2) + (pow(B.getY() - C.getY(), 2)) + (pow(B.getZ() - C.getZ(), 2))));
	double AB = fabs(sqrt(pow(A.getX() - B.getX(), 2) + (pow(A.getY() - B.getY(), 2)) + (pow(A.getZ() - B.getZ(), 2))));
	return AC + BC + AB;
}

// Determine Triangle medicenter (x1 + x2 + x3)/3 , (y1 + y2 + y3)/3, (z1 + z2 + z3)/3
Point Triangle::TriangleMedicenter()const
{
	return Point
	((this->A.getX() + B.getX() + C.getX()) / 3,
	(this->A.getY() + B.getY() + C.getY()) / 3,
	(this->A.getZ() + B.getZ() + C.getZ()) / 3);
}

// Operator < if Point lies on and inside Triangle
bool operator<(const Point& lhs, const Triangle& rhs)
{
	// razstot A do 0
	double OA = fabs(sqrt(pow(rhs.A.getX() - lhs.getX(), 2) + pow(rhs.A.getY() - lhs.getY(), 2) + pow(rhs.A.getZ() - lhs.getZ(), 2)));
	double OB = fabs(sqrt(pow(rhs.B.getX() - lhs.getX(), 2) + pow(rhs.B.getY() - lhs.getY(), 2) + pow(rhs.B.getZ() - lhs.getZ(), 2)));
	double OC = fabs(sqrt(pow(rhs.C.getX() - lhs.getX(), 2) + pow(rhs.C.getY() - lhs.getY(), 2) + pow(rhs.C.getZ() - lhs.getZ(), 2)));
	double sum = OA + OB + OC;
	return sum < rhs.TrianglePerimeter();
}

// Operator > if Point lies on and outside Triangle
bool operator >(const Point& lhs, const Triangle& rhs)
{
	double OA = fabs(sqrt(pow(rhs.A.getX() - lhs.getX(), 2) + pow(rhs.A.getY() - lhs.getY(), 2) + pow(rhs.A.getZ() - lhs.getZ(), 2)));
	double OB = fabs(sqrt(pow(rhs.B.getX() - lhs.getX(), 2) + pow(rhs.B.getY() - lhs.getY(), 2) + pow(rhs.B.getZ() - lhs.getZ(), 2)));
	double OC = fabs(sqrt(pow(rhs.C.getX() - lhs.getX(), 2) + pow(rhs.C.getY() - lhs.getY(), 2) + pow(rhs.C.getZ() - lhs.getZ(), 2)));
	double sum = OA + OB + OC;
	return sum > rhs.TrianglePerimeter();
}

// Operator == if Point is on one of the sides of Triangle
bool Triangle::operator ==(const Point& p)
{
	Line ab(A, B);
	Line ac(A, C);
	Line bc(B, C);
	return(ab + p || ac + p || bc + p); //operator from Line+
}

std::istream& operator>>(std::istream& in, Triangle& rhs)
{
	std::cout << "Please enter first point " << std:: endl;
	in >> rhs.A;
	std::cout << "Please enter second point " << std::endl;
	in >> rhs.B;
	std::cout << "Please enter third point " << std::endl;
	in >> rhs.C;
	return in;
}