#include "../inc/HumanA.hpp"

void HumanA::attack(){
	cout << this->name << " attacks with their " << this->weapon.getType() << endl;
}
