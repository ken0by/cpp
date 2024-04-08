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
		Weapon();
		~Weapon();
		const string getType();
		void setType(const string getType());
};

#endif
