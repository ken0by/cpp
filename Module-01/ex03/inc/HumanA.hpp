#ifndef HUMANA_H
# define HUMANA_H
# include <iostream>
# include <string>
# include <cstdlib>

using namespace std;

class HumanA{
	private:
		string name;
		string weapon;
	public:
		HumanA(string name, string weapon);
		~HumanA();
		void attack();
};

#endif
