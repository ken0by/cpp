#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	private:
		std::string name;
		int health;
		int energy;
		int attack_points;
		int	guard;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		int guarding(void) const;
		ScavTrap &operator = (const ScavTrap &other);
		void attack(const std::string& target);
		void guardGate(void);
		~ScavTrap();
};

#endif
