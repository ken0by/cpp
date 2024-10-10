#include "../inc/RPN.hpp"

RPN::RPN() {
	std::cout << "RPN default constructor called!" << std::endl;
}

RPN::RPN(const RPN& other) {
	std::cout << "RPN copy constructor called!" << std::endl;
}

RPN& RPN::operator=(const RPN& other){	if (this != &other) {

	}

	return (*this);
}

RPN::~RPN() {
	std::cout << "RPN destructor called!" << std::endl;
}

