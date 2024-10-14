#include "../inc/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	this->_myStack = other._myStack;
}

RPN& RPN::operator=(const RPN& other) {
	this->_myStack = other._myStack;
	return (*this);
}

RPN::~RPN() {}

bool isOperator(char nb) {
	return nb == '+' || nb == '-' || nb == '*' || nb == '/';
}

double	operation(char op, int a, int b) {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0) {
				std::cerr << ("Error: division by zero.") << std::endl;
				exit (1);
			}
			return a / b;
	}
	return 0.0;
}


void RPN::startRPN(std::string nbs) {
	std::stringstream ss(nbs);
	std::string token;

	while (ss >> token) {
		if (std::isdigit(token[0])) {
			double nb = token[0] - '0';
			_myStack.push(nb);
		} else if (isOperator(token[0])) {
			if (_myStack.size() < 2) {
				std::cerr << "Error: not enough operands for operator " << token << std::endl;
			}
			int b = _myStack.top();
			_myStack.pop();
			int a = _myStack.top();
			_myStack.pop();
			double result = operation(token[0], a, b);
			_myStack.push(result);
		}
	}
}

double RPN::getResult() {
	if (_myStack.empty()) {
		std::cerr << ("Error: stack is empty") << std::endl;
		exit (1);
	}
	double result = _myStack.top();
	_myStack.pop();
	if (!_myStack.empty()){
		std::cerr << "Error: invalid RPN expression" << std::endl;
		exit (1);
	}
	return result;
}
