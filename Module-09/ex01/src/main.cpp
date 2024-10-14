#include "../inc/RPN.hpp"

bool isOperator(char nb);

bool check_arg(std::string stack) {
	std::stack<int> cStack;

	for(size_t i = 0; i < stack.size(); i++) {
		char nb = stack[i];
		if (std::isdigit(nb)) {
			cStack.push(1);
		} else if (isOperator(nb)) {
			if (cStack.size() < 2) {
				return false; // Not enough operands
			}
			cStack.pop();
			cStack.pop();
			cStack.push(1);
		} else if (std::isspace(nb)) {
			//Ignore
		} else {
			return false;
		}
	}
	return cStack.size() == 1;
}

int main(int argc, char **argv) {
	if (argc != 2){
		std::cerr << "Error: enter a valid mathematical expresion (1 + 2 - 3 + 2 * 2 / 4)." << std::endl;
		return 1;
	}
	if (!check_arg(argv[1])) {
		std::cerr << "Invalid input. The expression is not a valid RPN." << std::endl;
		return 2;
	}
	RPN rpn;
	rpn.startRPN(argv[1]);
	double result = rpn.getResult();
	std::cout << result << std::endl;
	return 0;
}
