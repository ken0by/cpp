#include "../inc/Cat.hpp"

Cat::Cat(){
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other){
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Cat assignment operator called" << std::endl;
	this->type = other.type;
	return *this;
}

void Cat::makeSound() const{
	std::cout << "Meau!" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}
