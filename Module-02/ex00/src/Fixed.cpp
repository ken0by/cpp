#include "../inc/Fixed.hpp"

Fixed::Fixed(){
	this->nb = 0;
	cout << "Default constractor called" << endl;
}

Fixed::Fixed(const Fixed& other){
	cout << "Copy constractor called" << endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other){
	cout << "Copy assignment operator called" << endl;
	setRawBits(other.getRawBits());
	return *this;
}

int Fixed::getRawBits(void) const{
	cout << "getRawBits member function called" << endl;
	return this->nb;
}

void Fixed::setRawBits(int const raw){
	this->nb = raw;
}

Fixed::~Fixed(){
	cout << "Destructor called" << endl;
}
