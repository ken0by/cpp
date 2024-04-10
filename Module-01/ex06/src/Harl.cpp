#include "../inc/Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void){
	cout << "[DEBUG]" << endl;
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << endl;
}

void Harl::info(void){
	cout << "[INFO]" << endl;
	cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << endl;
}

void Harl::warning(void){
	cout << "[WARNING]" << endl;
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << endl;
}

void Harl::error(void){
	cout << "[ERROR]" << endl;
	cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

void Harl::complain(string level){
	int x = 0;

	if (level == "DEBUG")
		x = 1;
	if (level == "INFO")
		x = 2;
	if (level == "WARNING")
		x = 3;
	if (level == "ERROR")
		x = 4;
	if (x == 0){
		cout << "[ Probably complaining about insignificant problems ]" << endl;
	}
	switch (x){
		case 0:
			break ;
		case 1:
			debug();
		case 2:
			info();
		case 3:
			warning();
		case 4:
			error();
	}
}
