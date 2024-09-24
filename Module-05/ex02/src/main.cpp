#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

void chat_test()
{
	try
	{
		Bureaucrat bureaucrat1("Alice", 50);
		Bureaucrat bureaucrat2("Bob", 30);
		Bureaucrat bureaucrat3("Charlie", 5);

		// Crear formularios
		ShrubberyCreationForm shrubberyForm("Alice");
		RobotomyRequestForm robotomyForm("Bob");
		PresidentialPardonForm pardonForm("Charlie");

		// Intentar firmar los formularios
		std::cout << std::endl;
		std::cout << "SIGNING FORMS..." << std::endl;
		std::cout << std::endl;

		bureaucrat2.executeForm(shrubberyForm); // Bob firma
		bureaucrat2.executeForm(robotomyForm);	 // Bob firma
		bureaucrat3.executeForm(pardonForm);	 // Charlie firma

		// Intentar ejecutar los formularios
		std::cout << std::endl;
		std::cout << "EXECUTING FORMS..." << std::endl;
		std::cout << std::endl;

		bureaucrat1.executeForm(shrubberyForm); // Fallará, no tiene permiso
		bureaucrat2.executeForm(robotomyForm);	// Ejecuta y muestra el resultado
		bureaucrat3.executeForm(pardonForm);	// Ejecuta y muestra el resultado

		// Firmar el formulario de arbustos antes de ejecutarlo
		bureaucrat1.executeForm(shrubberyForm);	// Ahora debería funcionar
		bureaucrat1.executeForm(shrubberyForm); // Ahora debería ejecutarse
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testShrubberyCreationForm()
{
	std::cout << "---- TEST SHRUBBERY CREATION FORM ----" << std::endl;

	Bureaucrat bureaucrat1("Alice", 150);	// No puede firmar
	Bureaucrat bureaucrat2("Bob", 145);		// Puede firmar
	Bureaucrat bureaucrat3("Charlie", 137); // Puede ejecutar

	ShrubberyCreationForm shrubberyForm("Home");

	// Intentar firmar y ejecutar
	bureaucrat2.executeForm(shrubberyForm);	// Éxito en firma
	bureaucrat1.executeForm(shrubberyForm); // Fallo en ejecución (no firmado)
	bureaucrat3.executeForm(shrubberyForm); // Éxito en ejecución
}

void testRobotomyRequestForm()
{
	std::cout << std::endl;
	std::cout << "---- TEST ROBOTOMY REQUEST FORM ----" << std::endl;

	Bureaucrat bureaucrat1("Alice", 80); // Puede firmar
	Bureaucrat bureaucrat2("Bob", 45);	 // Puede firmar y ejecutar

	RobotomyRequestForm robotomyForm("Charlie");

	// Firmar y ejecutar
	bureaucrat1.executeForm(robotomyForm);	   // Éxito en firma
	bureaucrat2.executeForm(robotomyForm); // Éxito en ejecución
}

void testPresidentialPardonForm()
{
	std::cout << std::endl;
	std::cout << "---- TEST PRESIDENTIAL PARDON FORM ----" << std::endl;

	Bureaucrat bureaucrat1("Alice", 30); // Puede firmar
	Bureaucrat bureaucrat2("Bob", 5);	 // Puede firmar y ejecutar

	PresidentialPardonForm pardonForm("Charlie");

	// Firmar y ejecutar
	bureaucrat1.executeForm(pardonForm);	 // Éxito en firma
	bureaucrat2.executeForm(pardonForm); // Éxito en ejecución
}

void testMultipleFormsAndBureaucrats()
{
	std::cout << std::endl;
	std::cout << "---- TEST MULTIPLE FORMS AND BUREAUCRATS ----" << std::endl;

	Bureaucrat bureaucrat1("Alice", 50);  // No puede firmar
	Bureaucrat bureaucrat2("Bob", 25);	  // Puede firmar
	Bureaucrat bureaucrat3("Charlie", 5); // Puede firmar y ejecutar

	ShrubberyCreationForm shrubberyForm("Garden");
	RobotomyRequestForm robotomyForm("Eve");
	PresidentialPardonForm pardonForm("Frank");

	// Intentar firmar
	bureaucrat2.executeForm(shrubberyForm);	// Éxito
	bureaucrat2.executeForm(shrubberyForm); // Éxito

	bureaucrat3.executeForm(robotomyForm);	   // Éxito
	bureaucrat3.executeForm(robotomyForm); // Éxito

	bureaucrat3.executeForm(pardonForm);	 // Éxito
	bureaucrat3.executeForm(pardonForm); // Éxito
}

void chat_test_2()
{
	try
	{
		testShrubberyCreationForm();
		testRobotomyRequestForm();
		testPresidentialPardonForm();
		testMultipleFormsAndBureaucrats();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	std::cout << "CHAT_TEST" << std::endl;
	std::cout << "=========" << std::endl;
	std::cout << std::endl;
	chat_test();
	std::cout << std::endl;
	std::cout << std::endl;

	// std::cout << "CHAT_TEST_2" << std::endl;
	// std::cout << "===========" << std::endl;
	// std::cout << std::endl;
	// chat_test_2();
	// std::cout << std::endl;
	// std::cout << std::endl;
	return 0;
}
