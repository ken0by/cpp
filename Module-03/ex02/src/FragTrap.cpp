#include "../inc/FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
	std::cout << "FragTrap Default constractor called" << std::endl;
	this->name = "Default";
	this->health = 100;
	this->energy = 100;
	this->attack_points = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
	std::cout << "FragTrap " << name << " constractor called" << std::endl;
	this->name = name;
	this->health = 100;
	this->energy = 100;
	this->attack_points = 30;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other){
	std::cout << "FragTrap copy constractor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other){
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = other.getName();
	this->health = other.getHealth();
	this->energy = other.getEnergy();
	this->attack_points = other.getAttackPoints();
	return *this;
}

void FragTrap::attack(const std::string& target){
	if (this->health <= 0){
		std::cout << "FragTrap " << this->name << " can't attack " << target << ", is dead!" << std::endl;
		return ;
	}

	if (this->energy <= 0){
		std::cout << "FragTrap " << this->name << " can't attack " << target << ", don't have energy!" << std::endl;
		return ;
	}

	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_points << " points of damge!" << std::endl;
	this->energy -= 1;
}

void FragTrap::highFiveGuys(void){
	if (this->health <= 0){
		std::cout << "FragTrap " << this->name << " can't have five, is dead!" << std::endl;
		return ;
	}
	if (this->energy <= 0){
		std::cout << "FragTrap " << this->name << " can't have five, don't have energy!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << ": want to have five ✋" << std::endl;
	this->energy -= 1;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
}
