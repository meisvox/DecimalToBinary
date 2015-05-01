// Binary.h		Author: Vox
// Contains the declarations for the Binary class.
//
#ifndef BINARY_H
#define BINARY_H
#include <iostream>
using namespace std;

// Binary:
// The Binary class is an ADT representing a binary number. The number is
// stored as an array of bool. Each bool represents a bit with true = 1 and
// false = 0. The Binary class overloads the following operators: assisgnment,
// equality, inequality, addition (+ & +=), subtration (- & -=), odtream, and 
// istream.
// Assumptions: The Binary class reformats itself to remove all leading zeros
// after any operations which could result in a change in value.
//
class Binary {
	// ostream: prints Binary to ostream
	// pre-conditions: none
	// post-conditions: the values of m_binNum and printed to the ostream
	//
	friend ostream& operator<<(ostream &sout, const Binary &bin);
	
	// istream: inputs a Binary from keyboard
	// pre-conditions: none
	// post-conditions: sets bin equal to a Binary of value num (input from 
	// keyboard)
	//
    friend istream& operator>>(istream &sin, Binary &bin);

public:
// constructors:
	// default constructor: creates a Binary number equal to zero
	// pre-conditions: none
	// post-conditions: m_binNum intialized with m_size = 1, m_binNum[0] set
	//		 to false, m_positive set to true.
	//
	Binary();

	// constructor(int num): creates a Binary equal to num
	// pre-conditions: none
	// post-conditions: m_positive is set according to value of num,  m_binNum 
	//		is intialized with proper number of sig figs (no leading 0) and  
	//		the proper fields are set true.
	//
	Binary(int num);

	// copy constructor: creates a Binary equal to bin
	// pre-conditions: none
	// post-conditions: m_positive, m_size, and m_binNum are all set to these
	//		respective values of bin
	//
	Binary(const Binary &bin);

	// destructor
	// pre-conditions: none
	// post-condition: deletes values stores in m_binNum
	//
	~Binary();

// accessors:
	// getSize: returns m_size
	// pre-conditions: none
	// post-conditions: none
	//
	int getSize() const;

	// getPositive: returns m_positive
	// pre-conditions: none
	// post-conditions: none
	//
	bool getPositive() const;

	// getBit: return the value at index bit, if bit is out of range false is 
	//		returned
	// pre-conditions: none
	// post-conditions: none
	//
	bool getBit(int bit) const;

// mutators:
	// setBit: sets value at index bit to true
	// pre-conditions: none
	// post-conditions: m_binNum[bit] set true if bit < m_size and bit >= 0
	//
	void setBit(int bit);

	// clearBit: sets value at index bit to false
	// pre-conditions: none
	// post-conditions: m_binNum[bit] set false if bit < m_size and bit >= 0.
	//					Checks for and removes leading zeros.
	//
	void clearBit(int bit);

	// toggleBit: reverses the value at index bit
	// pre-conditions: none
	// post-conditions: m_binNum[bit] set to !m_binNum[bit] if bit < m_size and
	//		bit >= 0. 
	//					Checks for and removes leading zeros.
	//
	void toggleBit(int bit);

// operators:
	// assignment: creates a Binary equal to bin
	// pre-conditions: none
	// post-conditions: m_positive, m_size, and m_binNum are all set to these
	//		respective values of bin
	//
	const Binary& operator=(const Binary &bin);

	// equality: bit-by-bit comparison. returns true if values are equal else 
	//		returns false
	// pre-conditions: none
	// post-conditions: none
	//
	bool operator==(const Binary &bin) const;

	// inequality: bit-by-bit comparison. returns true if values are not equal 
	//		else returns false
	// pre-conditions: none
	// post-conditions: none
	//
	bool operator!=(const Binary &bin) const;

	// addition: adds two Binarys and returns a new Binary equal to 
	//		the sum
	// pre-conditions: none
	// post-conditions: none
	//
	Binary operator+(const Binary &bin) const;

	// subtraction: subtracts two Binarys and returns a Binary equal to
	//		the difference
	// pre-conditions: none
	// post-conditions: none
	//
	Binary operator-(const Binary &bin) const;

	// plus-equals: adds two Binarys and sets the left-operand to the value of 
	//		the sum.
	// pre-conditions: none
	// post-conditions: this is set to a new Binary equal to the sum of itself 
	//		and bin
	//
	Binary& operator+=(const Binary &bin);

	// minus-equals: subtracts two Binarys and sets the left-operand to the  
	//		value of the difference.
	// pre-conditions: none
	// post-conditions: this is set to a new Binary equal to the difference of 
	//		itself and	bin
	//
	Binary& operator-=(const Binary &bin);
	
private:
	// setPositive: sets the value of m_positive
	// pre-conditions: none
	// post-conditions: m_positive set to false if num < 0, else m_positive set 
	//		to true.
	//
	void setPositive(int num);

	// setBinNum: sets the m_binNum fields
	// pre-conditions: none
	// post-conditions: for every index less than m_size, m_binNum[index] is  
	//		set to the value of num % 2 == 1
	//
	void setBinNum(int num);

	// checkFormat: checks for leading zeros
	// pre-conditions: none
	// post-conditions: removes leading zeros and resizes m_binNum accordingly
	//
	void checkFormat();

	// reformat: removes leading zeros
	// pre-conditions: none
	// post-conditions: removes leading zeros and resizes m_binNum accordingly
	//
	void reformat(int size);

	// getSigFigs:  returns number of significant figures of num in binary
	// pre-conditions: none
	// post-conditions: none
	//
	int getSigFigs(int num) const;

	// twoToThePower: returns 1 if pow <= 0, else returns two to the power pow
	// pre-conditions: none
	// post-conditions: none
	//
	int twoToThePower(int num) const;

	// convertToDec(): returns the value of this in decimal form
	// pre-conditions: none
	// post-conditions: none
	//
	int convertToDec() const;
	
	bool *m_binNum;
	bool m_positive;
	int m_size;
};

#endif