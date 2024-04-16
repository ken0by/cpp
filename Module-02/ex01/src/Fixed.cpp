#include "../inc/Fixed.hpp"

float ft_power(float value, int x){
	float result;

	if (!x)
		return 1;
	if (x < 0){
		value = 1 / value;
		x *= -1;
	}
	result = value;
	while (--x)
		result *= value;
	return result;
}

Fixed::Fixed(){
	std::cout << "Default constractor called" << std::endl;
}

Fixed::Fixed(const int i){
	std::cout << "Int constractor called" << std::endl;
	this->nb = i << this->bits;
}

Fixed::Fixed(const float x){
	std::cout << "Float constractor called" << std::endl;
	this->nb = roundf(x * ft_power(2, this->bits));
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constractor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator = (const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	this->nb = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const{
	return this->nb;
}

void Fixed::setRawBits(int const raw){
	this->nb = raw;
}

int Fixed::toInt() const{
	return (this->nb >> this->bits);
}

float Fixed::toFloat() const{
	return (this->nb * ft_power(2, this->bits));
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator << (std::ostream& str, Fixed const &nb){
	return (str <<  nb.toFloat());
}
