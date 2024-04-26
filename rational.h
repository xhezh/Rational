#pragma once
#include <iostream>
#include <numeric>
#include <string>
class RationalDivisionByZero : public std::runtime_error {
public:
	RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
	}
};
class Rational {
	int numerator_;
	int denominator_;
	void Reduce(int64_t numerator, int64_t denominator);
public:
	Rational();
	Rational(int numerator); // NOLINT
	Rational(int numerator, int denominator);
	int GetNumerator() const;
	int GetDenominator() const;
	void SetNumerator(int numerator);
	void SetDenominator(int denominator);
	Rational operator+() const;
	Rational operator-() const;
	Rational& operator++();
	Rational& operator--();
	Rational operator++(int);
	Rational operator--(int);
	friend Rational& operator+=(Rational& lhs, const Rational& rhs);
	friend Rational& operator*=(Rational& lhs, const Rational& rhs);
	friend bool operator==(const Rational& lhs, const Rational& rhs);
	friend bool operator>(const Rational& lhs, const Rational& rhs);
};
Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational& operator-=(Rational& lhs, const Rational& rhs);
Rational& operator/=(Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
std::ostream& operator<<(std::ostream& stream, const Rational& rational);
std::istream& operator>>(std::istream& stream, Rational& rational);
