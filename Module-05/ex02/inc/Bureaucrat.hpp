#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	class GradeTooHighException : public std::exception{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception{
	public:
		const char *what() const throw();
	};

	Bureaucrat(const std::string &name, int grade);

	const std::string &getName() const;
	int getGrade() const;
	void signForm(AForm &form);
	void executeForm(AForm &form) const;

	void incrementGrade();
	void decrementGrade();

	friend std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
};

#endif
