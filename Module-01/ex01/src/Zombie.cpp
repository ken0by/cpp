#include "../inc/Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie(){
	std::cout << this->name << ": has been destroyed..." << std::endl;
}
