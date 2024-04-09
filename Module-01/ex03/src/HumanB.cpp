#include "../inc/HumanB.hpp"

void HumanB::attack(){
	cout << this->name << " attacks with their " << this->weapon->getType() << endl;
}

void HumanB::setWeapon(Weapon &type){
	this->weapon = &type;
}
