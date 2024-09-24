#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		PresidentialPardonForm(PresidentialPardonForm& copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& other);

		void execute(Bureaucrat const &executor) const;
		std::string getTarget() const ;
};

#endif
