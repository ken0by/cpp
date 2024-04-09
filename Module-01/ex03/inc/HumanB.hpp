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
		Weapon *weapon;
	public:
		HumanB(string name) : name(name){}
		void attack();
		void setWeapon(Weapon &type);
};

#endif
