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
	cout << "Default constractor called" << endl;
}

Fixed::Fixed(const int i){
	cout << "Int constractor called" << endl;
	this->nb = i << this->bits;
}

Fixed::Fixed(const float x){
	cout << "Float constractor called" << endl;
	this->nb = roundf(x * ft_power(2, this->bits));
}

Fixed::Fixed(const Fixed& other){
	cout << "Copy constractor called" << endl;
	*this = other;
}

Fixed& Fixed::operator = (const Fixed &other){
	cout << "Copy assignment operator called" << endl;
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
	cout << "Destructor called" << endl;
}

ostream& operator << (ostream& str, Fixed const &nb){
	return (str <<  nb.toFloat());
}
