#include "VectorLengthException.h"

const char* VectorLengthException::ex() const throw () 
{
	return "ERROR! Vector length is zero!";
}