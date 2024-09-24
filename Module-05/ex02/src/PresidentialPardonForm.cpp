#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default") {
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
	std::cout << "Constructor PresidentialPardonForm with target " << target << " called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Destructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& copy): AForm(copy), target(copy.getTarget()) {
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->target = other.getTarget();
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
	{
		throw GradeTooLowException();
	}
	if (executor.getGrade() > getGradeToSign())
	{
		throw GradeTooLowException();
	}

	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
	return this->target;
}
