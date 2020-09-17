#pragma once

// Abstract class ELEMENT with virtual function
class Element
{
public:
	Element();
	virtual void print()const = 0;
	virtual ~Element();
};