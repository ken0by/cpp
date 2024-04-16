#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <string>
#include <iomanip>

class ClapTrap{
	private:
		std::string name;
		int health = 10;
		int energy = 10;
		int attack = 0;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		~ClapTrap();
};

#endif
