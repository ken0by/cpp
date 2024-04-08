#include "../inc/Zombie.hpp"

Zombie* zombieHorde(int N, string name){
	//Alojar memoria xa N zombies
	Zombie* horde = new Zombie[N];

	//Iniciar los zombies con el nombre proporcionado
	for (int i = 0; i < N; ++i){
		horde[i].setName(name);
	}

	return horde;
}
