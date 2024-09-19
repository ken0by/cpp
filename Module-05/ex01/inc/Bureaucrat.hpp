#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	// Excepciones personalizadas
	class GradeTooHighException : public std::exception{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception{
	public:
		const char *what() const throw();
	};

	// Constructor
	Bureaucrat(const std::string &name, int grade);

	// Getters
	const std::string &getName() const;
	int getGrade() const;

	// Métodos para modificar el grado
	void incrementGrade();
	void decrementGrade();

	// Sobrecarga del operador de inserción <<
	friend std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
};

#endif
