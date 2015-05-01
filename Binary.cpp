#ifndef BINARY_CPP
#define BINARY_CPP
#include "Binary.h"

// Binary.cpp		Author: Vox
// Contains the definitions for the Binary class.
// The Binary class is an ADT representing a binary number. The number is
// stored as an array of bool. Each bool represents a bit with true = 1 and
// false = 0. The Binary class overloads the following operators: assisgnment,
// equality, inequality, addition (+ & +=), subtration (- & -=), odtream, and 
// istream.
// Assumptions: The Binary class reformats itself to remove all leading zeros
// after any operations which could result in a change in value.
//


// default constructor: creates a Binary number equal to zero
// pre-conditions: none
// post-conditions: m_binNum intialized with m_size = 1, m_binNum[0] set to false,
//		m_positive set to true.
//
Binary::Binary() {
	m_size = 1;
	m_binNum = new bool[m_size];
	m_binNum[0] = false;
	m_positive = true;	
}


// constructor(int num): creates a Binary equal to num
// pre-conditions: none
// post-conditions: m_positive is set according to value of num,  m_binNum is 
//		intialized with proper number of sig figs (no leading 0) and the 
//		proper fields are set true.
//
Binary::Binary(int num) {
	setPositive(num);
	m_size = getSigFigs(num);
	m_binNum = new bool[m_size];
	setBinNum(num);
}


// copy constructor: creates a Binary equal to bin
// pre-conditions: none
// post-conditions: m_positive, m_size, and m_binNum are all set to these
//		respective values of bin
//
Binary::Binary(const Binary &bin) {
	if(this != &bin) {
		m_positive = bin.m_positive;
		m_size = bin.m_size;
		m_binNum = new bool[m_size];
		for(int i = 0; i < m_size; i++) {
			m_binNum[i] = bin.m_binNum[i];
		}
	}
}


// destructor
// pre-conditions: none
// post-condition: deletes values stores in m_binNum
//
Binary::~Binary() {
	if(m_binNum != nullptr) {
		delete[] m_binNum;
	}
}

// getSize: returns m_size
// pre-conditions: none
// post-conditions: none
//
int Binary::getSize() const {
	return(m_size);
}


// getPositive: returns m_positive
// pre-conditions: none
// post-conditions: none
//
bool Binary::getPositive() const {
	return(m_positive);
}


// getBit: return the value at index bit, if bit is out of range false is 
//		returned
// pre-conditions: none
// post-conditions: none
//
bool Binary::getBit(int bit) const {
	if(bit < getSize() && bit >= 0) {
		return(m_binNum[bit]);
	}
	return(false);
}


// setBit: sets value at index bit to true
// pre-conditions: none
// post-conditions: m_binNum[bit] set true if bit < m_size and bit >= 0
//
void Binary::setBit(int bit) {
	if(bit < getSize() && bit >= 0) {
		m_binNum[bit] = true;
	}
}


// clearBit: sets value at index bit to false
// pre-conditions: none
// post-conditions: m_binNum[bit] set false if bit < m_size and bit >= 0.
//					Checks for and removes leading zeros.
//
void Binary::clearBit(int bit) {
	if(bit < getSize() && bit >= 0) {
		m_binNum[bit] = false;
		checkFormat();
	}
}


// toggleBit: reverses the value at index bit
// pre-conditions: none
// post-conditions: m_binNum[bit] set to !m_binNum[bit] if bit < m_size and
//		bit >= 0. 
//					Checks for and removes leading zeros.
//
void Binary::toggleBit(int bit) {
	if(bit < getSize() && bit >= 0) {
		m_binNum[bit] = !m_binNum[bit];
		checkFormat();
	}
}


// assignment operator: creates a Binary equal to bin
// pre-conditions: none
// post-conditions: m_positive, m_size, and m_binNum are all set to these
//		respective values of bin
//
const Binary& Binary::operator=(const Binary &bin) {
	if(this != &bin) {
		m_positive = bin.m_positive;
		m_size = bin.m_size;
		delete[] m_binNum;
		m_binNum = new bool[m_size];
		for(int i = 0; i < m_size; i++) {
			m_binNum[i] = bin.m_binNum[i];
		}
	}
	return(*this);
}


// equality: bit-by-bit comparison. returns true if values are equal else false
// pre-conditions: none
// post-conditions: none
//
bool Binary::operator==(const Binary &bin) const {
	if(getPositive() == bin.getPositive()) {
		if(getSize() == bin.getSize()) {
			for(int i = 0; i < getSize(); i++) {
				if(m_binNum[i] != bin.m_binNum[i]) {
					return(false);
				}
			}
			return(true);
		}
	}
	return(false);
}


// inequality: bit-by-bit comparison. returns true if values are not equal 
//		else false
// pre-conditions: none
// post-conditions: none
//
bool Binary::operator!=(const Binary &bin) const {
	if(!(*this == bin)) {
		return(true);
	}
	return(false);
}


// addition operator: adds two Binarys and returns a new Binary equal to 
//		the sum
// pre-conditions: none
// post-conditions: none
//
Binary Binary::operator+(const Binary &bin) const {
	int sum = convertToDec() + bin.convertToDec();
	return(Binary(sum));
}


// subtraction operator: subtracts two Binarys and returns a Binary equal to
//		the difference
// pre-conditions: none
// post-conditions: none
//
Binary Binary::operator-(const Binary &bin) const {
	int diff = convertToDec() - bin.convertToDec();
	return(Binary(diff));
}


// plus-equals: adds two Binarys and sets the left-operand to the value of the
//		sum.
// pre-conditions: none
// post-conditions: this is set to a new Binary equal to the sum of itself and
//		bin
//
Binary& Binary::operator+=(const Binary &bin) {
	*this = *this + bin;
	return(*this);
}


// minus-equals: subtracts two Binarys and sets the left-operand to the value 
//		of the difference.
// pre-conditions: none
// post-conditions: this is set to a new Binary equal to the difference of 
//		itself and	bin
//
Binary& Binary::operator-=(const Binary &bin) {
	*this = *this - bin;
	return(*this);
}


// setPositive: sets the value of m_positive
// pre-conditions: none
// post-conditions: m_positive set to false if num < 0, else m_positive set to
//		true.
//
void Binary::setPositive(int num) {
	if(num < 0) {
		m_positive = false;
	} else {
		m_positive = true;
	}
}


// setBinNum: sets the m_binNum fields
// pre-conditions: none
// post-conditions: for every index less than m_size, m_binNum[index] is set 
//		to the value of num % 2 == 1
//
void Binary::setBinNum(int num) {
	int index = 0;

	if(num < 0) {
		num = abs(num);
	}

	if(num == 0) {
		m_binNum[0] = false;
	}
	
	while(num > 0) {
		// if num mod 2 equals 1 set binNum[index] to true, else set 
		// binNum[index] to false. Then increment index.
		m_binNum[index++] = (num % 2 == 1) ? true : false;
		num /= 2;
    }
}


// checkFormat: checks for leading zeros
// pre-conditions: none
// post-conditions: removes leading zeros and resizes m_binNum accordingly
//
void Binary::checkFormat() {
	int count = getSize() - 1;
	while(!m_binNum[count] && count > 0) {
		count--;
	}

	if(count < getSize() - 1) {
		reformat(count + 1);
	}
}

// reformat: removes leading zeros
// pre-conditions: none
// post-conditions: removes leading zeros and resizes m_binNum accordingly
//
void Binary::reformat(int size) {
	if(size > 0) {
		m_size = size;
		bool *temp = new bool[size];
		for(int i = 0; i < size; i++) {
			temp[i] = m_binNum[i];
		}

		delete[] m_binNum;
		m_binNum = new bool[m_size];
		for(int i = 0; i < size; i++) {
			m_binNum[i] = temp[i];
		}

		delete[] temp;
	} else {
		*this = Binary();
	}
}


// getSigFigs:  returns number of significant figures of num in binary
// pre-conditions: none
// post-conditions: none
//
int Binary::getSigFigs(int num) const {
	if(num < 0) {
		num = abs(num);
	} 
	
	// special case not fullfilled by loop
	if(num == 2) {
		return(2);
	}

	for(int i = 0; i < num; i++) {
		if(twoToThePower(i) > num) {
			return(i);
		}
	}
	return(1);
}


// twoToThePower: returns 1 if pow <= 0, else returns two to the power pow
// pre-conditions: none
// post-conditions: none
//
int Binary::twoToThePower(int pow) const{
	if(pow <= 0) {
		return(1);
	}
	return(2 * twoToThePower(pow - 1));
}


// convertToDec(): returns the value of this in decimal form
// pre-conditions: none
// post-conditions: none
//
int Binary::convertToDec() const {
	int total = 0;
	for(int i = m_size - 1; i >= 0; i--) {
		if(m_binNum[i]) {
			total += twoToThePower(i);
		}
	}

	if(!m_positive) {
		total = -total;
	}

	return(total);
}


// ostream: prints Binary to ostream
// pre-conditions: none
// post-conditions: the values of m_binNum and printed to the ostream
//
ostream& operator<<(ostream &sout, const Binary &bin) {
	if(!bin.m_positive) {
		sout << "-";
	}

	for(int i = bin.getSize() - 1; i >= 0; i--) {
		sout << bin.m_binNum[i];
	}

	return(sout);
}


// istream: inputs a Binary from keyboard
// pre-conditions: none
// post-conditions: sets bin equal to a Binary of value num (input from keyboard)
//
istream& operator>>(istream &sin, Binary &bin) {
	int num;
	sin >> num;
	bin = Binary(num);
	return(sin);
}


#endif