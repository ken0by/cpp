#include "../inc/Zombie.hpp"
#include <cstdlib>

class Zombie;

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(){
	Zombie* zombie1;
	Zombie* zombie2;
	Zombie* zombie3;

	zombie1 = newZombie("Rick");
	zombie1->announce();
	zombie2 = newZombie("Morty");
	zombie2->announce();
	zombie3 = newZombie("Summer");
	zombie3->announce();
	randomChump("Jerry");
	randomChump("Beth");
	randomChump("Pickle rick");

	//Free memory
	delete zombie1;
	delete zombie2;
	delete zombie3;

	//system("leaks -q zombie");
	return 0;
}
