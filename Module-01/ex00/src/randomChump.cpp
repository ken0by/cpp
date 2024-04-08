#include "../inc/Zombie.hpp"

Zombie* newZombie(string name);

void randomChump(string name){
	Zombie *zombie;
	zombie = newZombie(name);
	zombie->announce();
	delete zombie;
}
