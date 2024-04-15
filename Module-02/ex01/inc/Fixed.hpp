#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>

using namespace std;

class Fixed{
	private:
		int nb;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float x);
		Fixed(const Fixed& other);
		Fixed& operator = (const Fixed& other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		~Fixed();
};

ostream& operator << (ostream& str, Fixed const &nb);

#endif
