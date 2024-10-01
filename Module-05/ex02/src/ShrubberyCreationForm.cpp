#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}



ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "Constructor ShrubberyCreationForm with target " << target << " called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Destructor ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy): AForm(copy), target(copy.getTarget()){
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->target = other.getTarget();
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToSign())
	{
		throw Bureaucrat::GradeTooLowException();
	}
	if (!this->getSigned())
	{
		throw AForm::FormNotSignedException();
	}

	std::string filename = this->target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file)
	{
		std::cerr << "Error creating file." << std::endl;
		//return;
	}

	file << "         ,@@@@@@@," << std::endl;
	file << "     ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	file << "  ,&%%&%&%%&,@@@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	file << " ,%&%%&%&&&&&@@@@@@@/@@@@@@@,88888888888" << std::endl;
	file << " %&&&&&&&&&&&&&@@@@@@@@@@@/88888888888888" << std::endl;
	file << "  %&&&&&&&&&&&&&@@@@@@@/88888888888888888" << std::endl;
	file << "   %&&&&&&&&&&&&&@@@@@/8888888888888888888" << std::endl;
	file << "    %&&&&&&&&&&&&&@@@/88888888888888888888" << std::endl;
	file << "      %&&&&&&&&&&&&@/88888888888888888888" << std::endl;
	file << "        %&&&&&&&&&@/88888888888888888888" << std::endl;
	file << "          %&&&&&&@/88888888888888888888" << std::endl;
	file << "             %&&&@/88888888888888888888" << std::endl;
	file << "                @@/88888888888888888888" << std::endl;

	file.close();
}

std::string ShrubberyCreationForm::getTarget() const {
	return (this->target);
}
