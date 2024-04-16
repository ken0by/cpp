#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	std::cout << "ScavTrap Default constractor called" << std::endl;
	this->name = "Default";
	this->health = 100;
	this->energy = 50;
	this->attack_points = 20;
	this->guard = 0;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	std::cout << "ScavTrap " << name << " constractor called" << std::endl;
	this->name = name;
	this->health = 100;
	this->energy = 50;
	this->attack_points = 20;
	this->guard = 0;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other){
	std::cout << "ScavTrap copy constractor called" << std::endl;
}

int ScavTrap::guarding(void) const{
	return this->guard;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = other.getName();
	this->health = other.getHealth();
	this->energy = other.getEnergy();
	this->attack_points = other.getAttackPoints();
	this->guard = other.guarding();
	return *this;
}

void ScavTrap::attack(const std::string& target){
	if (this->health <= 0){
		std::cout << "ScavTrap " << this->name << " can't attack " << target << ", is dead!" << std::endl;
		return ;
	}

	if (this->energy <= 0){
		std::cout << "ScavTrap " << this->name << " can't attack " << target << ", don't have energy!" << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_points << " points of damge!" << std::endl;
	this->energy -= 1;
}

void ScavTrap::guardGate(void){
	if (this->energy <= 0){
		std::cout << "ScavTrap " << this->name << " can't Gate mode, don't have energy!" << std::endl;
		return ;
	}
	if (this->health <= 0){
		std::cout << "ScavTrap " << this->name << " can't Gate mode, is dead!" << std::endl;
		return ;
	}
	if (this->guard == 0){
		std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
		this->guard = 1;
		this->energy -=1;
	}
	else
		std::cout << "ScavTrap " << this->name << " is almost in Gate mode!" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called" << std::endl;
}
