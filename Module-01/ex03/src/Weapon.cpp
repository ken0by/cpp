#include "../inc/Weapon.hpp"

const string &Weapon::getType()
{
	return this->type;
}

void Weapon::setType(string type){
	this->type = type;
}
