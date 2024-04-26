#include "rational.h"
void Rational::Reduce(int64_t numerator, int64_t denominator) {
	if (denominator == 0) {
		throw RationalDivisionByZero{};
	}
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
	int64_t gcd = std::gcd(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	numerator_ = static_cast<int>(numerator);
	denominator_ = static_cast<int>(denominator);
}
Rational::Rational() {
	Reduce(0, 1);
}
Rational::Rational(int numerator) {
	Reduce(numerator, 1);
}
Rational::Rational(int numerator, int denominator) {
	Reduce(numerator, denominator);
}
int Rational::GetNumerator() const {
	return numerator_;
}
int Rational::GetDenominator() const {
	return denominator_;
}
void Rational::SetNumerator(int numerator) {
	Reduce(numerator, denominator_);
}
void Rational::SetDenominator(int denominator) {
	Reduce(numerator_, denominator);
}
Rational Rational::operator+() const {
	return *this;
}
Rational Rational::operator-() const {
	return Rational{ -numerator_, denominator_ };
}
Rational& Rational::operator++() {
	Reduce(static_cast<int64_t>(numerator_) + denominator_, denominator_);
	return *this;
}
Rational& Rational::operator--() {
	Reduce(static_cast<int64_t>(numerator_) - denominator_, denominator_);
	return *this;
}
Rational Rational::operator++(int) {
	auto old_value = *this;
	Reduce(static_cast<int64_t>(numerator_) + denominator_, denominator_);
	return old_value;
}
Rational Rational::operator--(int) {
	auto old_value = *this;
	Reduce(static_cast<int64_t>(numerator_) - denominator_, denominator_);
	return old_value;
}
Rational& operator+=(Rational& lhs, const Rational& rhs) {
	int64_t lcm = static_cast<int64_t>(lhs.denominator_) * rhs.denominator_ / std::gcd(lhs.denominator_, rhs.denominator_);
	int64_t numerator = static_cast<int64_t>(lhs.numerator_) * lcm / lhs.denominator_ + static_cast<int64_t>(rhs.numerator_) * lcm / rhs.denominator_;
	int64_t denominator = lcm;
	lhs.Reduce(numerator, denominator);
	return lhs;
}
Rational& operator*=(Rational& lhs, const Rational& rhs) {
	int64_t numerator = static_cast<int64_t>(lhs.numerator_) * rhs.numerator_;
	int64_t denominator = static_cast<int64_t>(lhs.denominator_) * rhs.denominator_;
	lhs.Reduce(numerator, denominator);
	return lhs;
}
bool operator==(const Rational& lhs, const Rational& rhs) {
	return (lhs.numerator_ == rhs.numerator_ && lhs.denominator_ == rhs.denominator_);
}
bool operator>(const Rational& lhs, const Rational& rhs) {
	int64_t lcm = static_cast<int64_t>(lhs.denominator_) * rhs.denominator_ / std::gcd(lhs.denominator_, rhs.denominator_);
	int64_t numerator1 = static_cast<int64_t>(lhs.numerator_) * lcm / lhs.denominator_;
	int64_t numerator2 = static_cast<int64_t>(rhs.numerator_) * lcm / rhs.denominator_;
	return (numerator1 > numerator2);
}
Rational operator+(const Rational& lhs, const Rational& rhs) {
	Rational rational = lhs;
	rational += rhs;
	return rational;
}
Rational operator-(const Rational& lhs, const Rational& rhs) {
	Rational rational = lhs;
	rational -= rhs;
	return rational;
}
Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational rational = lhs;
	rational /= rhs;
	return rational;
}
Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational rational = lhs;
	rational *= rhs;
	return rational;
}
Rational& operator-=(Rational& lhs, const Rational& rhs) {
	return lhs += -rhs;
}
Rational& operator/=(Rational& lhs, const Rational& rhs) {
	return lhs *= Rational(rhs.GetDenominator(), rhs.GetNumerator());
}
bool operator!=(const Rational& lhs, const Rational& rhs) {
	return !(lhs == rhs);
}
bool operator<(const Rational& lhs, const Rational& rhs) {
	return (rhs > lhs);
}
bool operator>=(const Rational& lhs, const Rational& rhs) {
	return (lhs > rhs || lhs == rhs);
}
bool operator<=(const Rational & lhs, const Rational & rhs) {
	return (lhs < rhs || lhs == rhs);
}
std::ostream& operator<<(std::ostream& stream, const Rational& rational) {
	stream << rational.GetNumerator();
	if (rational.GetDenominator() != 1) {
		stream << '/' << rational.GetDenominator();
	}
	return stream;
}
std::istream& operator>>(std::istream& stream, Rational& rational) {
	std::string s;
	stream >> s;
	int numerator = 0;
	int denominator = 0;
	bool f = false;
	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] == '/') {
			numerator = std::stoi(s.substr(0, i));
			denominator = std::stoi(s.substr(i + 1));
			f = true;
		}
	}
	if (!f) {
		numerator = stoi(s);
		denominator = 1;
	}
	rational.SetNumerator(numerator);
	rational.SetDenominator(denominator);
	return stream;
}