#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

using namespace std;

class Zombie{
	private:
		string name;
	public:
		//Constructor
		Zombie();
		//Destructor
		~Zombie();
		void setName(string newName){
			name = newName;
		}
		Zombie* zombieHorde(int N, string name);
		void announce(void){
			cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
		}
};

#endif
