#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie{
	private:
		std::string name;
	public:
		//Constructor
		Zombie();
		//Destructor
		~Zombie();
		void setName(std::string newName){
			name = newName;
		}
		Zombie* zombieHorde(int N, std::string name);
		void announce(void){
			std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
		}
};

#endif
