#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other.getType()){
	std::cout << "Ice copy constructor called" << std::endl;
}

AMateria *Ice::clone() const{
	return new Ice(*this);
}

void Ice::use(ICharacter &target){
	std::cout << "Ice: * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice(){
	std::cout << "Ice destructor called" << std::endl;
}
