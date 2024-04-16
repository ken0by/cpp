#ifndef HUMANB_H
# define HUMANB_H
# include "../inc/Weapon.hpp"
# include <iostream>
# include <string>
# include <cstdlib>

class HumanB{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name) : name(name){}
		void attack();
		void setWeapon(Weapon &type);
};

#endif
