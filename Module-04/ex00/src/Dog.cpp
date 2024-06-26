#include "../inc/Dog.hpp"

Dog::Dog(){
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other){
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Dog assignment operator called" << std::endl;
	this->type = other.type;
	return *this;
}

void Dog::makeSound() const{
	std::cout << "Bark!" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}
