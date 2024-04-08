#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

using namespace std;

class Zombie{
	private:
		string name;
	public:
		Zombie();
		~Zombie();
		Zombie(string name) : name(name) {}
		void randomChump(string name);
		void announce(void){
			cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
		}
};

#endif
