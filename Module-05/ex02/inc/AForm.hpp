#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int grade;
	const int gradeToSign;

public:
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class FormNotSignedException : public std::exception {
		public:
				const char *what() const throw();
	};

	AForm();
	AForm(const std::string name);
	AForm(const std::string &name, int gradeToSign, int grade);
	AForm(const std::string &name, bool isSigned, int gradeToSign, int grade);
	virtual ~AForm();

	AForm(AForm& copy);
	AForm &operator=(const AForm& other);

	const std::string &getName() const;
	bool getSigned() const;
	int getGrade() const;
	int getGradeToSign() const;

	void beSigned(const Bureaucrat &bureaucrat);
	int checkgrade(int grade);
	virtual void execute(Bureaucrat const &executor) const = 0;

};
std::ostream &operator<<(std::ostream &os, const AForm &Aform);

#endif
