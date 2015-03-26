#include <iostream>
#include <string>

#include "Rational.h"

using namespace std;

int main(int argc, char* argv[]) {
	Rational r1(3,4);
	Rational r2(1,2);
	Rational r3(r2);

	cout << "Copying r2 to r3..." << endl;
	
	if ( r3 == r2 ) {
		cout << "Copy successful!" << endl;
		cout << "r2: " << r2 << endl;
		cout << "r3: " << r3 << endl;
	}

	r3 = r1;
	cout << "Assigning r1 to r3..." << endl;

	if ( r3 == r1 ) {
		cout << "Assignment successful!" << endl;
		cout << "r1: " << r1 << endl;
		cout << "r3: " << r3 << endl;
	}

	cout << "r1: " << r1 << endl;
	cout << "Negative r1: " << -r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r3: " << r3 << endl;

	cout << r1 << " + " << r2 << " = " << (r1 + r2) << endl;
	cout << r1 << " - " << r2 << " = " << (r1 - r2) << endl;
	cout << r1 << " * " << r2 << " = " << (r1 * r2) << endl;
	cout << r1 << " / " << r2 << " = " << (r1 / r2) << endl;

	if ( r1 == r1 ) {
		cout << r1 << " equals " << r3 << endl;
	}

	if ( r1 != r2 ) {
		cout << r1 << " does not equal " << r2 << endl;
	}

	if ( r1 > r2 ) {
		cout << r1 << " is greater than " << r2 << endl;
	}

	if ( r1 >= r2 ) {
		cout << r1 << " is greater than or equal to " << r2 << endl;
	}

	if ( r2 < r1 ) {
		cout << r2 << " is less than " << r1 << endl;
	}

	if ( r2 <= r1 ) {
		cout << r2 << " is less than or equal to " << r1 << endl;
	}
}

/*	Output
	Copying r2 to r3...
	Copy successful!
	r2: 1/2
	r3: 1/2
	Assigning r1 to r3...
	Assignment successful!
	r1: 3/4
	r3: 3/4
	r1: 3/4
	Negative r1: -3/4
	r2: 1/2
	r3: 3/4
	3/4 + 1/2 = 5/4
	3/4 - 1/2 = 1/4
	3/4 * 1/2 = 3/8
	3/4 / 1/2 = 3/2
	3/4 equals 3/4
	3/4 does not equal 1/2
	3/4 is greater than or equal to 1/2
	1/2 is less than or equal to 3/4
*/