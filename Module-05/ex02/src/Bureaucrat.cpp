#include "../inc/Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
	if (grade < 1){
		throw GradeTooHighException();
	}
	else if (grade > 150){
		throw GradeTooLowException();
	}
	std::cout << "Bureaucrat constructor called" << std::endl;
}

const std::string &Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade - 1 < 1){
		throw GradeTooHighException();
	}
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade + 1 > 150){
		throw GradeTooLowException();
	}
	grade++;
}

void Bureaucrat::signForm(AForm &form) {
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm &form) const {
	form.execute(*this);
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
