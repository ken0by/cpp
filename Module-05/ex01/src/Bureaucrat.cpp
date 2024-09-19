#include "../inc/Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low!";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade){
	if (grade < 1){
		GradeTooHighException();
	}
	else if (grade > 150){
		GradeTooLowException();
	}
}

const std::string &Bureaucrat::getName() const{
	return name;
}

int Bureaucrat::getGrade() const{
	return grade;
}

void Bureaucrat::incrementGrade(){
	if (grade - 1 < 1){
		GradeTooHighException();
	}
	grade--;
}

void Bureaucrat::decrementGrade(){
	if (grade + 1 > 150){
		GradeTooLowException();
	}
	grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
