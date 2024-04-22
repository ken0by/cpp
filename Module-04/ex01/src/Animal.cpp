#include "../inc/Animal.hpp"

Animal::Animal(){
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Default";
}

Animal::Animal(const Animal &other){
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = other.type;
}

Animal &Animal::operator=(const Animal &other){
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = other.type;
	return *this;
}

std::string Animal::getType(void) const{
	return this->type;
}

void Animal::makeSound(void) const{
	std::cout << "Default!" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}
