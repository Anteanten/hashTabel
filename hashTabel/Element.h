#ifndef ELEMENT_H
#define ELEMENT_H

#include "Hash.h"

class Element
{
private:
	// membervariables
public:
	// constructors, destructor, ...
	// memberfunctions
	// definition of == operator and != operator 
};

template<>
class Hash<Element>
{
public:
	unsigned int operator()(const Element& elem) const
	{
		// to be implement
		// the integer returned is calculated from data in elem
		return 0; // replace 0 with the calculated value
	}
};

#endif