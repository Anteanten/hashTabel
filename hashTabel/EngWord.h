#ifndef ENGWORD_H
#define ENGWORD_H

#include "Hash.h"
#include <string>

class EngWord
{
private:
	// membervariables
	std::string word;

public:
	EngWord(const std::string &word) {
		this->word = word;
	}
	~EngWord(){
	}

	std::string getWord() const {
		return word;
	}

	bool operator==(const EngWord & otherObj);
	bool operator!=(const EngWord & otherObj);
	// constructors, destructor, ...
	// memberfunctions
	// definition of == operator and != operator 
};

template<>
class Hash<EngWord>{
public:
	unsigned int operator()(const EngWord& elem) const
	{
		// to be implement
		// the integer returned is calculated from data in elem
		return 0; // replace 0 with the calculated value
	}
};

#endif