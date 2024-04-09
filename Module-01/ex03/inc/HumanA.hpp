#ifndef HUMANA_H
# define HUMANA_H
# include <iostream>
# include <string>
# include <cstdlib>
# include "Weapon.hpp"

using namespace std;

class HumanA{
	private:
		string name;
		Weapon &weapon;
	public:
		HumanA(string name, Weapon &weapon) : name(name), weapon(weapon){}
		void attack();
};

#endif
