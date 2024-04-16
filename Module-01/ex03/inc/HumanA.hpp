#ifndef HUMANA_H
# define HUMANA_H
# include <iostream>
# include <string>
# include <cstdlib>
# include "Weapon.hpp"

class HumanA{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon){}
		void attack();
};

#endif
