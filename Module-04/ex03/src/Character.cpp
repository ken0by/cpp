#include "../inc/Character.hpp"

Character::Character() : ICharacter(){
	std::cout << "Character constructor called" << std::endl;
	this->name = "def";
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = nullptr;
}

Character::Character(std::string const &name){
	std::cout << "Character name constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = nullptr;
}

std::string const &Character::getName() const{
	return this->name;
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; ++i){
		if (!this->inventory[i]){
			this->inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx){
	if (idx < 0 || idx >= 4)
		return;
	// No eliminar la Materia, simplemente quitarla del inventario
	this->inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target){
	if (idx < 0 || idx >= 4 || !this->inventory[idx])
		return;
	this->inventory[idx]->use(target);
}

Character::~Character(){
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		delete this->inventory[i];
}
