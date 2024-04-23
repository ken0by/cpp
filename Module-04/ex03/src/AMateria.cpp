#include "../inc/AMateria.hpp"

AMateria::AMateria(){
	std::cout << "AMateria constructor called" << std::endl;
	this->type = nullptr;
}

AMateria::AMateria(std::string const & type){
	this->type = type;
}

std::string const &AMateria::getType(void) const{
	return this->type;
}

AMateria::~AMateria(){
	std::cout << "AMateria destructor called" << std::endl;
}
