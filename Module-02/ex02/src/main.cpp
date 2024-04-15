#include "../inc/Fixed.hpp"

void	big_tests(int value_of_b, float value_of_c)
{
	cout << "Initialisations" << endl;
	cout << "Initialising a Fixed variable a." << endl;
	Fixed a;
	cout << "Value of a is: " << a << endl;

	cout << "Initialising a Fixed variable b with an int (" << value_of_b
		<< ")." << endl;
	const Fixed b(value_of_b);
	cout << "Value of b is: " << b << endl;

	cout << "Initialising a Fixed variable c with a float (" << value_of_c
		<< ")" << endl;
	const Fixed c(value_of_c);
	cout << "Value of c is: " << c << endl;

	cout << "Initialising a Fixed variable d with another Fixed variable (c)." << endl;
	Fixed d(c);
	cout << "Value of d is: " << d << endl;

	cout << "Using assignation operator (a = b)" << endl;
	a = b;
	cout << "Value of a is: " << a << endl << endl;

	cout << "Using comparison operators" << endl;
	cout << "a < c is " << (a < c) << endl;
	cout << "a < b is " << (a < b) << endl;
	cout << "a > c is " << (a > c) << endl;
	cout << "a > b is " << (a > b) << endl;
	cout << "a <= c is " << (a <= c) << endl;
	cout << "a <= b is " << (a <= b) << endl;
	cout << "a >= c is " << (a >= c) << endl;
	cout << "a >= b is " << (a >= b) << endl;
	cout << "a == c is " << (a == c) << endl;
	cout << "a == b is " << (a == b) << endl;
	cout << "a != c is " << (a != c) << endl;
	cout << "a != b is " << (a != b) << endl << endl;

	cout << "Using binary operators" << endl;
	cout << "c + a = " << (c + a) << endl;
	cout << "c - a = " << (c - a) << endl;
	cout << "c * a = " << (c * a) << endl;
	cout << "c / a = " << (c / a) << endl << endl;

	cout << "Using unary operators" << endl;
	cout << "a++ = " << a++ << endl;
	cout << "Value of a is: " << a << endl;
	cout << "++a = " << ++a << endl;
	cout << "Value of a is: " << a << endl;
	cout << "a-- = " << a-- << endl;
	cout << "Value of a is: " << a << endl;
	cout << "--a = " << --a << endl;
	cout << "Value of a is: " << a << endl << endl;

	cout << "Using other functions" << endl;
	cout << "c.toInt() = " << c.toInt() << endl;
	cout << "c.toFloat() = " << c.toFloat() << endl;
	cout << "min(a, d) = " << Fixed::min(a, d) << endl;
	cout << "min(b, c) = " << Fixed::min(b, c) << endl;
	cout << "max(a, d) = " << Fixed::max(a, d) << endl;
	cout << "max(b, c) = " << Fixed::max(b, c) << endl << endl;
}

void tests()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	cout << a << endl;
	cout << ++a << endl;
	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;
	cout << b << endl;
	cout << Fixed::max( a, b ) << endl;
}

int main( void )
{
	big_tests(14, 50.125f);
	cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Now same thing but with negative numbers:" << endl;
	cout << "-----------------------------------------" << endl;
	cout << endl;
	big_tests(-12, -80.175829380f);
	// tests();
}
