#include "../inc/Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void){
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void){
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void){
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level){
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
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	switch (x){
		case 0:
			break ;
		case 1:
			Harl::debug();
			break ;
		case 2:
			Harl::info();
			break ;
		case 3:
			Harl::warning();
			break ;
		case 4:
			Harl::error();
			break ;
	}
}
