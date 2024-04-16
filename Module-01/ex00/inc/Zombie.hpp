#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		Zombie(std::string name) : name(name) {}
		void randomChump(std::string name);
		void announce(void){
			std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
		}
};

#endif
