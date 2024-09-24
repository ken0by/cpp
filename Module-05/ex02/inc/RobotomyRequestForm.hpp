#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm(RobotomyRequestForm& copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& other);

		void execute(Bureaucrat const &executor) const;
		std::string getTarget() const ;
};

#endif
