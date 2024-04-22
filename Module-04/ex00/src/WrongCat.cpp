#include "../inc/WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << "WrongCat contructor called" << std::endl;
	this->type = "Cat_wrong";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other){
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
	std::cout << "WrongCat assignment operator called" << std::endl;
	this->type = other.type;
	return *this;
}

void WrongCat::makeSound(void) const{
	std::cout << "Wrong meau!" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}
