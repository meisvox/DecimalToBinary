#include <iostream>
#include "Binary.h"
using namespace std;

// main: driver for HW1
// preconditions: 	none
// postconditions: 	Outputs results to the console window and returns 0.
//	
int main() {
	Binary a, b(42), c(b), d = -13, x, y = x + 1;

	cout << "Enter integer to be converted to binary:  ";
	cin >> a;
	cout << "The binary representation of this number is: " << endl;
	cout << a << endl;
	cout << "The 4th bit (four bits away from bit 0) is: " << endl;
	cout << a.getBit(4) << endl << endl;

	cout << "Compute c = a + b" << endl;
	c = a + b;
	cout << "c = " << c << endl;
	cout << "Compute d = a + b - c" << endl;
	d = a + b - c;
	cout << "d = " << d << endl << endl;

	cout << "Does a == c? " << endl;
	cout << ( (a == c) ? "a == c" : "a != c") << endl << endl;
   
   	cout << "Test assignment operators" << endl;
   	x = c = d = d;    y += a -= b += b;
   	cout << "x = " << x << "    y = " << y << endl << endl;

   	a.setBit(-1);			// handle bad input
	a.setBit(3);			// set 3rd bit (three over from bit zero)
	a.setBit(1000);			// set 1000th bit; handle as desired, but don't crash
	a.clearBit(3);			// clear 3rd bit
	a.clearBit(10000);		// clear 10000th bit
	a.toggleBit(3);			// toggle 3rd bit

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "any key to exit." << endl;
	cin.get();
	return(0);
}