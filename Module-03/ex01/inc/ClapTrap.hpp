#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <string>
#include <iomanip>

class ClapTrap{
	private:
		std::string name;
		int health;
		int energy;
		int attack_points;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator = (const ClapTrap &other);
		std::string getName(void) const;
		int getHealth(void) const;
		int getEnergy(void) const;
		int getAttackPoints() const;
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		virtual ~ClapTrap();
};

#endif
