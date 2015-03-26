#ifndef __RATIONAL_H
#define __RATIONAL_H

#include <string>

class Rational {
private:
	int mNumerator;
	int mDenominator;

	void Normalize();

	int gcd(const int &n, const int &d) const;

public:
	Rational();

	Rational(const int &Numerator, const int &Denominator);

	Rational(const Rational &other);

	int GetNumerator() const;
	void SetNumerator(int newNumerator);

	int GetDenominator() const;
	void SetDenominator(int newDenominator);

	bool Equals(const Rational &other) const;

	Rational Add(const Rational &other) const;

	std::string ToString() const;

	Rational operator=(const Rational &other);

	friend std::ostream& operator<<(std::ostream &lhs, const Rational &rhs);
	friend Rational operator+(const Rational &lhs, const Rational &rhs);
	friend Rational operator-(const Rational &rational);
	friend Rational operator-(const Rational &lhs, const Rational &rhs);
	friend Rational operator*(const Rational &lhs, const Rational &rhs);
   	friend Rational operator/(const Rational &lhs, const Rational &rhs);
	friend bool operator==(const Rational &lhs, const Rational &rhs);
	friend bool operator!=(const Rational &lhs, const Rational &rhs);
	friend bool operator<(const Rational &lhs, const Rational &rhs);
	friend bool operator>(const Rational &lhs, const Rational &rhs);
	friend bool operator<=(const Rational &lhs, const Rational &rhs);
	friend bool operator>=(const Rational &lhs, const Rational &rhs);

};

#endif
