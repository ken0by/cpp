#include "../inc/Zombie.hpp"

Zombie* newZombie(std::string name);

void Zombie::randomChump(std::string name){
	Zombie *zombie;
	zombie = newZombie(name);
	zombie->announce();
	delete zombie;
}
