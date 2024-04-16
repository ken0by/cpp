#include "../inc/Zombie.hpp"
#include <cstdlib>

class Zombie;

Zombie* zombieHorde(int N, std::string name);

int main(){
	int N = 10;
	std::string name = "Puto";
	Zombie* horde = zombieHorde(N, name);
	for (int i = 0; i < N ; ++i){
		horde[i].announce();
	}
	delete[] horde;
	//system("leaks -q zombie");
	return 0;
}
