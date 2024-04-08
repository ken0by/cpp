#include "../inc/Weapon.hpp"

Weapon::Weapon(){}

Weapon::~Weapon(){}

const string getType(){
    return this->type;
}

void setType(string type){
    this->type = type;
}
