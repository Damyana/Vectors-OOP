#include <iostream>
#include <cmath>
#include <exception>

#include "Vector.h"
#include "VectorLengthException.h"

Vector::Vector() : Point() {} // Default constructor 
Vector::Vector(const Vector& rhs) {} // Copy Constructor
// Parameterized constructor
Vector::Vector(const Point& a, const Point& b) 
{
	getX() == b.getX() - a.getX();
	getY() == b.getY() - a.getY();
	getZ() == b.getZ() - a.getZ();

}
Vector::Vector(double x, double y, double z) : Point(x, y, z) {} // Parameterized constructor
 // Operator =
Vector& Vector::operator=(const Vector& rhs) 
{
	if (this != &rhs) 
	{
		Point::operator=(rhs);
	}
	return*this;
}
Vector::~Vector() {} // Destructor


// 1 - 5
// Length of Vector
double Vector::VectorLength()const 
{
	return sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
}

// Direction of Vector
Vector Vector::DirectionOfVector()const 
{
	try 
	{
		if (VectorLength() == 0) 
		{
			throw VectorLengthException(); // exception if length = 0
		}
		else 
		{
			return Vector(getX() / VectorLength(), getY() / VectorLength(), getZ() / VectorLength()); // this is vector direction formula
		}
	}
	catch (VectorLengthException& e) 
	{
		std::cout << e.ex() << std::endl;
	}
}

// Zero Vector x=y=z =0 -> zero vector
bool Vector::CheckZero()const 
{
	if (getX() == getY() == getZ() == 0) 
		return true;
	else 
		return false;
}

// Parallel Vector
bool Vector::CheckParallel(const Vector& v)const 
{
	// Exception
	try 
	{
		if (VectorLength() == 0 || v.VectorLength() == 0) // if one of 2 vectors have length = 0
			throw VectorLengthException(); // exception if length = 0
	}
	catch (VectorLengthException& e) 
	{
		std::cout << e.what() << std::endl;
	}

	// x:v1=y:v2=z:v3
	if ((this->getX() / v.getX()) == (this->getY() / v.getY()) == (this->getZ() / v.getZ()))
		return true;
	else
		return false;

}

// Perendicular Vector
bool Vector::CheckPerpendicular(const Vector& rhs)const
{
	try 
	{
		if (VectorLength() == 0 || rhs.VectorLength() == 0) // if one of 2 vectors have length = 0
			throw VectorLengthException(); // exception if length = 0

		// x.v1+y.v2+z.v3= 0
		if (((this->getX() * rhs.getX()) + (this->getY() * rhs.getY()) + (this->getZ() * rhs.getZ())) == 0) 
			return true;
		else
			return false;
	}
	catch (VectorLengthException& e) 
	{
		std::cout << e.what() << std::endl;
	}
}


// OPERATORS
// Addition (+) of 2 vectors:  a+v= (x, y, z) + (v1, v2, v3) = (x+v1, y+v2, z+v3);
Vector Vector::operator+(const Vector& rhs)const 
{
	// (RESULT: Vector)
	return Vector(this->getX() + rhs.getX(), this->getY() + rhs.getY(), this->getZ() + rhs.getZ());
}

// Subtraction (-) of 2 vectors:  a−v= (x, y, z)−(v1, v2, v3) = (x−v1, y−v2, z−v3);
Vector Vector::operator-(const Vector& rhs)const 
{
	// (RESULT: Vector)
	return Vector(this->getX() - rhs.getX(), this->getY() - rhs.getY(), this->getZ() - rhs.getZ());
}

// Multiplying (*) Vector with real number:  r∗a= (rx, ry, rz);
Vector Vector::operator*(double num)const 
{
	// (RESULT: Vector)
	return Vector(this->getX() * num, this->getY() * num, this->getZ() * num);
}

// Dot product or Scalar product of 2 Vectors (*):  a∗v=x.v1+y.v2+z.v3;
double Vector::operator*(const Vector& rhs)const 
{
	// (RESULT: Real number)
	return((this->getX() * rhs.getX()) + (this->getY() * rhs.getY()) + (this->getZ() * rhs.getZ()));
}

// Vector multiply 2 vectors Cross Product:  a∧v= (y.v3−z.v2,−x.v3+z.v1, x.v2−y.v1)
Vector Vector::operator^(const Vector& rhs)const 
{
	// (RESULT: Vector)
	return Vector(getY() * rhs.getZ() - getZ() * rhs.getY(), getZ() * rhs.getX() - getX() * rhs.getZ(), getX() * rhs.getY() - getY() * rhs.getX());
}

// Vector multiply 3 vectors Mixed Product:  w.(u×v) = (Wx*Ux*Vx + Wy*Uz*Vz + Wz*Ux*Uy) - (Wz*Uy*Vz - Wy*Ux*Vx - Wx*Uz*Vy)
double Vector::operator ()(const Vector& lhs, const Vector& rhs) 
{
	double x = getX() * lhs.getY() * rhs.getZ();
	double y = getY() * lhs.getZ() * rhs.getX();
	double z = getZ() * lhs.getX() * rhs.getY();
	double first = x + y + z;

	double x2 = getZ() * lhs.getY() * rhs.getX();
	double y2 = getX() * lhs.getZ() * rhs.getY();
	double z2 = getY() * lhs.getX() * rhs.getZ();
	double second = x2 + y2 + z2;

	return first - second;
}

// CIN
std::istream& operator>>(std::istream& in, Vector& rhs)
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

// COUT
std::ostream& operator<<(std::ostream& out, const Vector& rhs) 
{
	out << rhs.getX() << ", " << rhs.getY() << ", " << rhs.getZ();
	return out;
}