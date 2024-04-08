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
		Weapon(string type);
		const string getType();
		void setType(string type);
};

#endif
