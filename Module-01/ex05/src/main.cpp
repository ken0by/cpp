#include "../inc/Harl.hpp"

int main(int argc, char **argv){
	Harl Steve;
	Steve.complain("DEBUG");
	Steve.complain("INFO");
	Steve.complain("WARNING");
	Steve.complain("ERROR");
	std::cout << std::endl;
	if (argc == 2)
		Steve.complain(argv[1]);

	return 0;
}
