#include "../inc/Fixed.hpp"

void	big_tests(int value_of_b, float value_of_c)
{
	std::cout << "Initialisations" << std::endl;
	std::cout << "Initialising a Fixed variable a." << std::endl;
	Fixed a;
	std::cout << "Value of a is: " << a << std::endl;

	std::cout << "Initialising a Fixed variable b with an int (" << value_of_b
		<< ")." << std::endl;
	const Fixed b(value_of_b);
	std::cout << "Value of b is: " << b << std::endl;

	std::cout << "Initialising a Fixed variable c with a float (" << value_of_c
		<< ")" << std::endl;
	const Fixed c(value_of_c);
	std::cout << "Value of c is: " << c << std::endl;

	std::cout << "Initialising a Fixed variable d with another Fixed variable (c)." << std::endl;
	Fixed d(c);
	std::cout << "Value of d is: " << d << std::endl;

	std::cout << "Using assignation operator (a = b)" << std::endl;
	a = b;
	std::cout << "Value of a is: " << a << std::endl << std::endl;

	std::cout << "Using comparison operators" << std::endl;
	std::cout << "a < c is " << (a < c) << std::endl;
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "a > c is " << (a > c) << std::endl;
	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a <= c is " << (a <= c) << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;
	std::cout << "a >= c is " << (a >= c) << std::endl;
	std::cout << "a >= b is " << (a >= b) << std::endl;
	std::cout << "a == c is " << (a == c) << std::endl;
	std::cout << "a == b is " << (a == b) << std::endl;
	std::cout << "a != c is " << (a != c) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl << std::endl;

	std::cout << "Using binary operators" << std::endl;
	std::cout << "c + a = " << (c + a) << std::endl;
	std::cout << "c - a = " << (c - a) << std::endl;
	std::cout << "c * a = " << (c * a) << std::endl;
	std::cout << "c / a = " << (c / a) << std::endl << std::endl;

	std::cout << "Using unary operators" << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "Value of a is: " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "Value of a is: " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "Value of a is: " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "Value of a is: " << a << std::endl << std::endl;

	std::cout << "Using other functions" << std::endl;
	std::cout << "c.toInt() = " << c.toInt() << std::endl;
	std::cout << "c.toFloat() = " << c.toFloat() << std::endl;
	std::cout << "min(a, d) = " << Fixed::min(a, d) << std::endl;
	std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl;
	std::cout << "max(a, d) = " << Fixed::max(a, d) << std::endl;
	std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl << std::endl;
}

void tests()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

int main( void )
{
	big_tests(14, 50.125f);
	std::cout << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Now same thing but with negative numbers:" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << std::endl;
	big_tests(-12, -80.175829380f);
	// tests();
}
