#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Default"), health(100), energy(100), attack_points(30){
	std::cout << "ClapTrap Default constractor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), health(100), energy(100), attack_points(30){
	std::cout << "ClapTrap " << name << " constractor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other){
	std::cout << "ClapTrap copy constractor called" << std::endl;
	*this = other;
}

std::string ClapTrap::getName(void) const{
	return this->name;
}

int ClapTrap::getHealth(void) const {
	return this->health;
}

int ClapTrap::getEnergy(void) const {
	return this->energy;
}

int ClapTrap::getAttackPoints(void) const {
	return this->attack_points;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = other.getName();
	this->health = other.getHealth();
	this->energy = other.getEnergy();
	this->attack_points = other.getAttackPoints();
	return *this;
}

void ClapTrap::attack(const std::string& target){
	if (this->health <= 0){
		std::cout << "ClapTrap " << this->name << " can't attack " << target << ", is dead!" << std::endl;
		return ;
	}

	if (this->energy <= 0){
		std::cout << "ClapTrap " << this->name << " can't attack " << target << ", don't have energy!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_points << " points of damge!" << std::endl;
	this->energy -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->health <= 0){
		std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name << " take " << amount << " points of damge!" << std::endl;
	this->health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->health <= 0){
		std::cout << "ClapTrap " << this->name << " can't repaired, is dead!" << std::endl;
		return ;
	}

	if (this->energy <= 0){
		std::cout << "ClapTrap " << this->name << " can't repaired, don't have energy!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name << " repeared " << amount << " points of health!" << std::endl;
	this->health += amount;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called" << std::endl;
}
