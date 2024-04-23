#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("cure"){
	std::cout << "Cure constractor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other.getType()){
	std::cout << "Cure copy constructor called" << std::endl;
}

AMateria *Cure::clone() const{
	return new Cure(*this);
}

void Cure::use(ICharacter &target){
	std::cout << "Cure: * heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure(){
	std::cout << "Cure destructor called" << std::endl;
}
