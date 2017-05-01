#ifndef ENGWORD_H
#define ENGWORD_H

#include "Hash.h"
#include <string>
#include <algorithm>

class EngWord
{
private:
	// membervariables
	std::string word;

public:
	EngWord() {
		word = "/NULL/";
	}
	EngWord(const std::string &word) {
		this->word = word;
	}
	~EngWord(){
	}

	std::string getWord() const {
		return word;
	}

	bool operator==(const EngWord & otherObj) {
		return getWord() == otherObj.getWord();
	}

	bool operator!=(const EngWord & otherObj) {
		return getWord() != otherObj.getWord();
	}
};

template<>
class Hash<EngWord>{
public:
	unsigned int operator()(const EngWord& elem) const {
		//I found this hash function in the course book and decided to use it
		//since for every word i multiply by a prime. Then the hash value should be
		//decided by size of word and specific letters.
		//Multiple should be a prime because otherwise if one multiply by 4 it every added value is just
		//twice as big then multiply by 2.
		int hash = 0;
		std::string word = elem.getWord();
		std::transform(word.begin(), word.end(), word.begin(), ::toupper);
		for(char ch : word) {
			//take -64 since all letters are uppercase and then A(65) becomes 1
			hash = hash * 11 + (ch - 64);
		}
		return hash;
	}
};

#endif