#include <iostream>
#include <string>

using namespace std;

#include "Rational.h"

Rational::Rational()
	: mNumerator(0), mDenominator(1) {
	Normalize();
}

Rational::Rational(const int &numerator, const int &denominator)
	: mNumerator(numerator), mDenominator(denominator) {
	Normalize();
}

Rational::Rational(const Rational &other)
	: mNumerator(other.mNumerator), mDenominator(other.mDenominator) {
	Normalize();
}

int Rational::GetNumerator() const {
	return mNumerator;
}

int Rational::GetDenominator() const {
	return mDenominator;
} 

void Rational::SetNumerator(int newNumerator) {
	mNumerator = newNumerator;
	Normalize();
}

void Rational::SetDenominator(int newDenominator) {
	mDenominator = newDenominator;
	Normalize();
}

void Rational::Normalize() {

	if ( (mNumerator < 0 && mDenominator < 0) 
	 || (mNumerator > 0 && mDenominator < 0) ) {
		mDenominator = -mDenominator;
		mNumerator = -mNumerator;
	}
	
	int n = mNumerator;
	int d = mDenominator;

	if ( n != 0 ) { 
		mNumerator /= gcd(n, d);
		mDenominator /= gcd(n, d);
	}
}

int Rational::gcd(const int &n, const int &d) const {
	int numerator = n;
	if (n < 0) {
		numerator = -n;
	}
	int denominator = d;
	while (numerator != denominator) {
		if (numerator > denominator) {
			numerator -= denominator;
		}
		else {
			denominator -= numerator;
		}
	}
	return numerator;
}

bool Rational::Equals(const Rational &other) const {
	return ((mNumerator == other.mNumerator) 
	 && (mDenominator == other.mDenominator));
}

Rational Rational::Add(const Rational &other) const {
	int newNumerator = (mNumerator * other.mDenominator) 
	 + (mDenominator * other.mNumerator);

	int newDenominator = (mDenominator * other.mDenominator);

	return Rational(newNumerator, newDenominator);
}

std::string Rational::ToString() const {
	string numerator;
	string denominator;
	string rational;
	
	numerator = std::to_string(mNumerator);
	denominator = std::to_string(mDenominator);

	if (mDenominator == 1 || mNumerator == 0) {
		rational += numerator;
	}
	else {
		rational += numerator; 
		rational += "/";
		rational += denominator;
	}

	return rational;
}

Rational Rational::operator=(const Rational &other) {
	mNumerator = other.mNumerator;
	mDenominator = other.mDenominator;
	return *this;
}

std::ostream& operator<<(std::ostream &lhs, const Rational &rhs) {
	lhs << rhs.ToString();
	return lhs;
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
	return lhs.Add(rhs);
}

Rational operator-(const Rational &rational) {
	return Rational(-rational.mNumerator,rational.mDenominator);
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
	int newNumerator = (lhs.mNumerator * rhs.mDenominator) 
	 - (lhs.mDenominator * rhs.mNumerator);

	int newDenominator = (lhs.mDenominator * rhs.mDenominator);

	return Rational(newNumerator, newDenominator);
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
	return Rational(lhs.mNumerator * rhs.mNumerator,
	 lhs.mDenominator * rhs.mDenominator);
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
	return Rational(lhs.mNumerator * rhs.mDenominator,
	 lhs.mDenominator * rhs.mNumerator);
}

bool operator==(const Rational &lhs, const Rational &rhs) {
	return ((lhs.mNumerator == rhs.mNumerator) 
	 && (lhs.mDenominator == rhs.mDenominator));
}

bool operator!=(const Rational &lhs, const Rational &rhs) {
	return ((lhs.mNumerator != rhs.mNumerator) 
	 || (lhs.mDenominator != rhs.mDenominator));
}

bool operator<(const Rational &lhs, const Rational &rhs) {
	return ((lhs.mNumerator / lhs.mDenominator) 
	 < (rhs.mNumerator / rhs.mDenominator));
}

bool operator>(const Rational &lhs, const Rational &rhs) {
	return ((lhs.mNumerator / lhs.mDenominator) 
	 > (rhs.mNumerator / rhs.mDenominator));
}

bool operator<=(const Rational &lhs, const Rational &rhs) {
	return ((lhs.mNumerator / lhs.mDenominator) 
	 <= (rhs.mNumerator / rhs.mDenominator));
}

bool operator>=(const Rational &lhs, const Rational &rhs) {
	return ((lhs.mNumerator / lhs.mDenominator) 
	 >= (rhs.mNumerator / rhs.mDenominator));
}