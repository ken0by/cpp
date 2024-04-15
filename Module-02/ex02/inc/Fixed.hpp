#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class Fixed
{
	private:
		int nb;
		static const int bits = 8;

	public:
		Fixed();
		Fixed(const int);
		Fixed(const float x);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		~Fixed();
		// Static functions
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		// Comparison operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Increment/decrement operators
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
};

ostream &operator<<(ostream &str, Fixed const &nb);

#endif
