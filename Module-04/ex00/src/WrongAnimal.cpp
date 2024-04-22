#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = "Def_wrong";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	this->type = other.type;
	return *this;
}

std::string WrongAnimal::getType(void) const{
	return this->type;
}

void WrongAnimal::makeSound(void) const{
	std::cout << "Wrong def!" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}
