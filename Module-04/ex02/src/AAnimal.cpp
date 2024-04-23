#include "../inc/AAnimal.hpp"

AAnimal::AAnimal(){
	std::cout << "AAnimal constructor called" << std::endl;
}

std::string AAnimal::getType(void) const{
	return this->type;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor called" << std::endl;
}
