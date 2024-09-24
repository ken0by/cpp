#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
    std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "Constructor RobotomyRequestForm with target " << target << " called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy), target(copy.getTarget())
{
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->target = other.getTarget();
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigned())
    {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToSign())
    {
        throw Bureaucrat::GradeTooLowException();
    }

    std::cout << "Drilling noises..." << std::endl;
    if (std::rand() % 2)
    {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy of " << target << " failed." << std::endl;
    }
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->target;
}
