#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <iomanip>

class Fixed{
	private:
		int nb;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator = (const Fixed& other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		~Fixed();
};

#endif
