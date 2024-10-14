#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <iostream>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int> _myStack;
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		void startRPN(std::string nbs);
		double getResult();
};

#endif
