#include "../inc/Form.hpp"

Form::Form() : name("default"), isSigned(false), grade(1), gradeToSign(1) {
	std::cout << "Form default Constructor called" << std::endl;
}

Form::Form(const std::string name) : name(name), isSigned(false), grade(1), gradeToSign(1) {
	std::cout << "Form " << name << " Constructor called" << std::endl;
}

Form::Form(const std::string &name, int grade, int gradeToSign) : name(name), isSigned(false), grade(checkgrade(grade)), gradeToSign(checkgrade(gradeToSign)) {
	std::cout << "Form " << name << " Constructor called" << std::endl;
}

Form::Form(const std::string &name, bool isSigned, int grade, int gradeToSign) : name(name), isSigned(isSigned), grade(checkgrade(grade)), gradeToSign(checkgrade(gradeToSign)) {
	std::cout << "Form " << name << " Constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form " << this->name << " Destructor called" << std::endl;
}

Form::Form(Form& copy): name(copy.name), isSigned(copy.isSigned), grade(copy.grade), gradeToSign(copy.gradeToSign) {
	std::cout << "Form Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->isSigned = other.getSigned();
	return *this;
}

int Form::checkgrade(int grade) {
	try {
		if (grade > 150)
			throw GradeTooHighException();
		if (grade < 1)
			throw GradeTooLowException();
	} catch (const GradeTooHighException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		return (1);
	} catch (const GradeTooLowException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
		return (1);
	}
	return (grade);
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const std::string &Form::getName() const {
	return name;
}

bool Form::getSigned() const {
	return isSigned;
}

int Form::getGrade() const {
	return grade;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign){
		throw GradeTooLowException();
	}
	isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form " << form.getName() << " is " << (form.getSigned() ? "signed" : "not signed") << "(Sing grade: " << form.getGradeToSign() << ", grade: " << form.getGrade() << ")";
	return os;
}
