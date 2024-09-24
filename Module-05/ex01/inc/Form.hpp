#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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

	Form();
	Form(const std::string name);
	Form(const std::string &name, int gradeToSign, int grade);
	Form(const std::string &name, bool isSigned, int gradeToSign, int grade);
	~Form();

	Form(Form& copy);
	Form &operator=(const Form& other);

	const std::string &getName() const;
	bool getSigned() const;
	int getGrade() const;
	int getGradeToSign() const;

	void beSigned(const Bureaucrat &bureaucrat);
	int checkgrade(int grade);

};
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
