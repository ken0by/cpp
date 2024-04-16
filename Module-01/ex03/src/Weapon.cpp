#include "../inc/Weapon.hpp"

const std::string &Weapon::getType()
{
	return this->type;
}

void Weapon::setType(string type){
	this->type = type;
}
