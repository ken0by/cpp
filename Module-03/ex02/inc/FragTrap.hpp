#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	private:
		std::string name;
		int health;
		int energy;
		int attack_points;
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		FragTrap &operator = (const FragTrap &other);
		void attack(const std::string& target);
		void highFiveGuys(void);
		~FragTrap();
};

#endif
