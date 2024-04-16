#include "../inc/contact.hpp"
#include "../inc/phonebook.hpp"


int main(){
	Phonebook phonebook;
	std::string cmd;

	while (true) {
		std::cout << "Enter one command (ADD, SEARCH , EXIT): ";
		std::cin >> cmd;

		if (std::cin.eof()){
			std::cout << "Ctrl-D detected. Exiting..." << std::endl;
			break ;
		}

		if (cmd == "ADD"){
			phonebook.add();
			std::cout << std::endl;
		} else if (cmd == "SEARCH") {
			phonebook.print_Phonebook();
			std::cout << std::endl;
		} else if (cmd == "EXIT") {
			std::cout << "Exiting..." << std::endl;
			break ;
		} else {
			std::cout << "Invalid command. Try again" << std::endl;
		}
	}
	return (0);
}
