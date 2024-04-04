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
		void announce( void );
		Zombie* newZombie(string name);
}

#endif
