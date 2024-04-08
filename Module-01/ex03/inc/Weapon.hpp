#ifndef WEAPON_H
# define WEAPON_H
# include <iostream>
# include <string>
# include <cstdlib>

using namespace std;

class Weapon{
	private:
		string type;
	public:
		Weapon(string type) : type(type){}
		const string getType();
		void setType(string type);
};

#endif
