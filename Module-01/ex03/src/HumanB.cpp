#include "../inc/HumanB.hpp"

void HumanB::attack(){
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &type){
	this->weapon = &type;
}
