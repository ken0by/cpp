#include "../inc/Harl.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Please enter a argument. DEBUG, INFO, WARNING, ERROR." << std::endl;
		return 0;
	}
	Harl Steve;

	Steve.complain(argv[1]);

	return 0;
}
