#ifndef WEAPON_H
# define WEAPON_H
# include <iostream>
# include <string>
# include <cstdlib>

class Weapon{
	private:
		std::string type;
	public:
		Weapon(std::string type) : type(type){}
		const std::string& getType();
		void setType(std::string type);
};

#endif
