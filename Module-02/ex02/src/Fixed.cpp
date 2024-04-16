#include "../inc/Fixed.hpp"

float ft_power(float value, int x){
	float result;

	if (!x)
		return 1;
	if (x < 0)
	{
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

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constractor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
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

std::ostream &operator << (std::ostream &str, Fixed const &nb){
	return (str << nb.toFloat());
}

// Static functions
Fixed &Fixed::min(Fixed &a, Fixed &b){
	return a.nb < b.nb ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	return a.nb < b.nb ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	return a.nb > b.nb ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	return a.nb > b.nb ? a : b;
}

// Comparison operators
bool Fixed::operator > (const Fixed &other) const{
	return this->nb > other.nb;
}

bool Fixed::operator < (const Fixed &other) const{
	return this->nb < other.nb;
}

bool Fixed::operator >= (const Fixed &other) const{
	return this->nb >= other.nb;
}

bool Fixed::operator <= (const Fixed &other) const{
	return this->nb <= other.nb;
}

bool Fixed::operator == (const Fixed &other) const{
	return this->nb == other.nb;
}

bool Fixed::operator != (const Fixed &other) const{
	return this->nb != other.nb;
}

// Arithmetic operators
Fixed Fixed::operator + (const Fixed &other) const{
	Fixed result;
	result.setRawBits(this->nb + other.nb);
	return result;
}

Fixed Fixed::operator - (const Fixed &other) const{
	Fixed result;
	result.setRawBits(this->nb - other.nb);
	return result;
}

Fixed Fixed::operator * (const Fixed &other) const{
	Fixed result;
	result.setRawBits((this->nb * other.nb) >> bits);
	return result;
}

Fixed Fixed::operator / (const Fixed &other) const{
	Fixed result;
	result.setRawBits((this->nb << bits) / other.nb);
	return result;
}

// Increment/decrement operators
Fixed &Fixed::operator++(){
	this->nb++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed &Fixed::operator--(){
	this->nb--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed temp = *this;
	--(*this);
	return temp;
}
