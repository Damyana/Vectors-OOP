#include "Tetrahedron.h"
#include <iostream>
#include "EqualPointException.h"
#include <exception>

// Default constructor
Tetrahedron::Tetrahedron()
{
	
}

// Parameterized constructor
Tetrahedron::Tetrahedron(const Point& a, const Point& b, const Point& c, const Point& d)
{
	try {
		if (a == b) 
		{
			std::cout << "First: " << a << " and " << "second point: " << b << std::endl;
			throw EqualPointException();
		}
		else if (a == c)
		{
			std::cout << "First: " << a << " and " << "third point: " << c << std::endl;
			throw EqualPointException();
		}
		else if (b == c)
		{
			std::cout << "Second: " << b << " and " << "third point: " << c << std::endl;
			throw EqualPointException();
		}
		else if (a == d) 
		{
			std::cout << "First: " << a << " and " << "forth point: " << d << std::endl;
			throw EqualPointException();
		}
		else if (b == d) 
		{
			std::cout << "Second: " << b << " and " << "forth point: " << d << std::endl;
			throw EqualPointException();
		}
		else if (c == d) 
		{
			std::cout << "Third: " << c << " and " << "forth point: " << d << std::endl;
			throw EqualPointException();
		}
		else
		{
			this->A = a;
			this->B = b;
			this->C = c;
			this->D = d;
		}

	}
	catch (EqualPointException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

// Copy constructor
Tetrahedron::Tetrahedron(const Tetrahedron& rhs)
{
	A = rhs.A;
	B = rhs.B;
	C = rhs.C;
	D = rhs.D;
}

// Operator =
Tetrahedron& Tetrahedron :: operator=(const Tetrahedron& other)
{
	if (this != &other)
	{
		Segment::operator=(other);
		A = other.A;
		B = other.B;
		C = other.C;
		D = other.D;
	}
	return *this;
}

// Destructor
Tetrahedron::~Tetrahedron()
{
}

// RightTetrahedron - All edges of Tetrahedron are equal
bool Tetrahedron::RegularTetrahedron() const
{
	// 6 edges
	Vector v1(A, B);
	Vector v2(A, C);
	Vector v3(B, C);
	Vector v4(A, D);
	Vector v5(B, D);
	Vector v6(C, D);

	// Here we use vector length of every edge of Tetrahedron
	double a = v1.VectorLength();
	double b = v2.VectorLength();
	double c = v3.VectorLength();
	double d = v4.VectorLength();
	double e = v4.VectorLength();
	double f = v4.VectorLength();

	// if edges are = -> Regular Tetrahedron
	if (a == b == c == d == e == f) return true;
	else return false;
}

// Orthogonal Tetrahedron - where every two of opposite edges are perpendicular
bool Tetrahedron::OrthogonalTetrahedron()const
{
	// AC perpendicular to BD
	if (((this->A.getX() * C.getX()) + (this->A.getY() * C.getY()) + (this->A.getZ() * C.getZ())) == 0) 
	{
		return true;
	}
	else if (((this->B.getX() * D.getX()) + (this->B.getY() * D.getY()) + (this->B.getZ() * D.getZ())) == 0) 
	{
		return true;
	}
	else
		return false;
}

// Surrounding Surface of Tetrahedron  sqrt3* a,2
double Tetrahedron::SurroundingSurface() const
{
	double getX = B.getX() - A.getX();
	double getY = B.getY() - A.getY();
	double getZ = B.getZ() - A.getZ();
	double a = sqrt(pow(getX, 2) + pow(getY, 2) + pow(getZ, 2));
	return sqrt(3) * (pow(a, 2));
}

// Volume of Tetrahedron a,3 / 6sqrt(2)
double Tetrahedron::TetrahedronVolume()const
{
	double getX = B.getX() - A.getX();
	double getY = B.getY() - A.getY();
	double getZ = B.getZ() - A.getZ();
	double a = sqrt(pow(getX, 2) + pow(getY, 2) + pow(getZ, 2));
	double res = (pow(a, 3) / sqrt(72));
	return res;
}

// Operator < if Point lies on and inside Tetrahedron
bool operator<(const Point& lhs, const Tetrahedron& rhs)
{
	double OA = fabs(sqrt(pow(rhs.A.getX() - lhs.getX(), 2) + pow(rhs.A.getY() - lhs.getY(), 2) + pow(rhs.A.getZ() - lhs.getZ(), 2)));
	double OB = fabs(sqrt(pow(rhs.B.getX() - lhs.getX(), 2) + pow(rhs.B.getY() - lhs.getY(), 2) + pow(rhs.B.getZ() - lhs.getZ(), 2)));
	double OC = fabs(sqrt(pow(rhs.C.getX() - lhs.getX(), 2) + pow(rhs.C.getY() - lhs.getY(), 2) + pow(rhs.C.getZ() - lhs.getZ(), 2)));
	double OD = fabs(sqrt(pow(rhs.D.getX() - lhs.getX(), 2) + pow(rhs.D.getY() - lhs.getY(), 2) + pow(rhs.D.getZ() - lhs.getZ(), 2)));
	double sum = OA + OB + OC + OD;
	return sum < rhs.TetrahedronVolume();
}

// Operator > if Point lies on and outside Tetrahedron
bool operator >(const Point& lhs, const Tetrahedron& rhs)
{
	double OA = fabs(sqrt(pow(rhs.A.getX() - lhs.getX(), 2) + pow(rhs.A.getY() - lhs.getY(), 2) + pow(rhs.A.getZ() - lhs.getZ(), 2)));
	double OB = fabs(sqrt(pow(rhs.B.getX() - lhs.getX(), 2) + pow(rhs.B.getY() - lhs.getY(), 2) + pow(rhs.B.getZ() - lhs.getZ(), 2)));
	double OC = fabs(sqrt(pow(rhs.C.getX() - lhs.getX(), 2) + pow(rhs.C.getY() - lhs.getY(), 2) + pow(rhs.C.getZ() - lhs.getZ(), 2)));
	double OD = fabs(sqrt(pow(rhs.D.getX() - lhs.getX(), 2) + pow(rhs.D.getY() - lhs.getY(), 2) + pow(rhs.D.getZ() - lhs.getZ(), 2)));
	double sum = OA + OB + OC + OD;
	return sum > rhs.TetrahedronVolume();
}

// Operator == if Point is on one of the sides of Tetrahedron
bool Tetrahedron::operator ==(const Point& p)
{
	Line ab(A, B);
	Line ac(A, C);
	Line bc(B, C);
	Line ad(A, D);
	Line bd(B, D);
	Line cd(C, D);

	return(ab + p || ac + p || bc + p || ad + p || bd + p || cd + p);
}

// COUT
std::ostream& operator<<(std::ostream& out, const Tetrahedron& rhs)
{
	return out << "Point A: " << rhs.A << "Point B: " << rhs.B << "Point C: " << rhs.C << "Point D: " << rhs.D;
}

// CIN
std::istream& operator>>(std::istream& in, Tetrahedron& rhs)
{
	std::cout << "Please enter first point \n";
	in >> rhs.A;
	std::cout << "Please enter second point \n";
	in >> rhs.B;
	std::cout << "Please enter third point \n";
	in >> rhs.C;
	std::cout << "Please enter forth point \n";
	in >> rhs.D;
	return in;
}