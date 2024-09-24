#include "../inc/AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), grade(1), gradeToSign(1) {
	std::cout << "AForm default Constructor called" << std::endl;
}

AForm::AForm(const std::string name) : name(name), isSigned(false), grade(1), gradeToSign(1) {
	std::cout << "AForm " << name << " Constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int grade, int gradeToSign) : name(name), isSigned(false), grade(checkgrade(grade)), gradeToSign(checkgrade(gradeToSign)) {
	std::cout << "AForm " << name << " Constructor called" << std::endl;
}

AForm::AForm(const std::string &name, bool isSigned, int grade, int gradeToSign) : name(name), isSigned(isSigned), grade(checkgrade(grade)), gradeToSign(checkgrade(gradeToSign)) {
	std::cout << "AForm " << name << " Constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm " << this->name << " Destructor called" << std::endl;
}

AForm::AForm(AForm& copy): name(copy.name), isSigned(copy.isSigned), grade(copy.grade), gradeToSign(copy.gradeToSign) {
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->isSigned = other.getSigned();
	return *this;
}

int AForm::checkgrade(int grade) {
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

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
};

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
};

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form isn't signed");
};

const std::string &AForm::getName() const {
	return name;
}

bool AForm::getSigned() const {
	return isSigned;
}

int AForm::getGrade() const {
	return grade;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (this->isSigned) {
		std::cout << "Form is already signed by " << bureaucrat.getName() << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() > this->gradeToSign){
		throw Bureaucrat::GradeTooLowException();
	} else {
		this->isSigned = true;
		std::cout << bureaucrat.getName() << " signed " << name << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform) {
	os << "AForm " << Aform.getName() << " is " << (Aform.getSigned() ? "signed" : "not signed") << "(Sing grade: " << Aform.getGradeToSign() << ", grade: " << Aform.getGrade() << ")";
	return os;
}
