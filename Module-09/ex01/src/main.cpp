#include "../inc/RPN.hpp"

void simple_test() {

}

void big_test() {

}
int main(int argc, char **argv) {
	if (argc != 2){
		std::cerr << "Error: enter a valid mathematical expresion (1 + 2 + 3)." << std::endl;
		return 1;
	}
	std::cout << "-----SIMPLE TEST-----\n" << std::endl;
	simple_test();
	std::cout << "\n" << std::endl;
	std::cout << "-----BIG TEST-----\n" << std::endl;
	big_test();
	std::cout << "\n" << std::endl;
	return 0;
}
