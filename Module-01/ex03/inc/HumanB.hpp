#ifndef HUMANB_H
# define HUMANB_H
# include "../inc/Weapon.hpp"
# include <iostream>
# include <string>
# include <cstdlib>

using namespace std;

class HumanB{
	private:
		string name;
		string weapon;
	public:
		HumanB(string name, string weapon);
		~HumanB();
		void attack();
		void setWeapon(Weapon club);
};

#endif
