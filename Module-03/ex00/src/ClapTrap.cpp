#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "Constractor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name){
	std::cout << "Name constractor called" << std::endl;
	this->name = name;
}

void ClapTrap::attack(const std::string& target){
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing" << this->attack << " points of damge!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){}

void ClapTrap::beRepaired(unsigned int amount){}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}
