#include "../inc/Fixed.hpp"

Fixed::Fixed(){
	this->nb = 0;
	std::cout << "Default constractor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constractor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(other.getRawBits());
	return *this;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->nb;
}

void Fixed::setRawBits(int const raw){
	this->nb = raw;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}
