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

		bureaucrat2.signForm(shrubberyForm); // Bob firma
		bureaucrat2.signForm(robotomyForm);	 // Bob firma
		bureaucrat3.signForm(pardonForm);	 // Charlie firma

		// Intentar ejecutar los formularios
		std::cout << std::endl;
		std::cout << "EXECUTING FORMS..." << std::endl;
		std::cout << std::endl;
		bureaucrat1.signForm(shrubberyForm); // Fallará, no tiene permiso
		bureaucrat2.executeForm(robotomyForm);	// Ejecuta y muestra el resultado
		bureaucrat3.executeForm(pardonForm);	// Ejecuta y muestra el resultado

		// Firmar el formulario de arbustos antes de ejecutarlo
		bureaucrat1.signForm(shrubberyForm);	// Ahora debería funcionar
		bureaucrat1.executeForm(shrubberyForm); // Ahora debería ejecutarse
		std::cout << "\nDESTRUCTOR\n" << std::endl;
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

	// Intentar firmar el formulario
	try {
		bureaucrat2.signForm(shrubberyForm); // Éxito en firma
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Intentar ejecutar el formulario con Alice (no tiene permiso)
	try {
		bureaucrat1.executeForm(shrubberyForm); // Fallará porque Alice no tiene suficiente rango para ejecutarlo
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Intentar ejecutar el formulario con Charlie (tiene permiso para ejecutarlo)
	try {
		bureaucrat3.executeForm(shrubberyForm); // Éxito en ejecución
		std::cout << "\nDESTRUCTOR\n" << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		std::cout << "\nDESTRUCTOR\n" << std::endl;
	}
}

void testRobotomyRequestForm()
{
	std::cout << std::endl;
	std::cout << "---- TEST ROBOTOMY REQUEST FORM ----" << std::endl;

	Bureaucrat bureaucrat1("Alice", 80); // Puede firmar
	Bureaucrat bureaucrat2("Bob", 45);	 // Puede firmar y ejecutar

	RobotomyRequestForm robotomyForm("Charlie");

	// Intentar firmar y ejecutar
	try {
		bureaucrat1.signForm(robotomyForm);    // Éxito en firma
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		bureaucrat2.executeForm(robotomyForm); // Éxito en ejecución
		std::cout << "\nDESTRUCTOR\n" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		std::cout << "\nDESTRUCTOR\n" << std::endl;
	}
}

void testPresidentialPardonForm()
{
	std::cout << std::endl;
	std::cout << "---- TEST PRESIDENTIAL PARDON FORM ----" << std::endl;

	Bureaucrat bureaucrat1("Alice", 30); // Puede firmar
	Bureaucrat bureaucrat2("Bob", 5);	 // Puede firmar y ejecutar

	PresidentialPardonForm pardonForm("Charlie");

	// Intentar firmar y ejecutar
	try {
		bureaucrat1.signForm(pardonForm);    // Éxito en firma
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		bureaucrat2.executeForm(pardonForm); // Éxito en ejecución
		std::cout << "\nDESTRUCTOR\n" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		std::cout << "\nDESTRUCTOR\n" << std::endl;
	}
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
	try {
		bureaucrat2.signForm(shrubberyForm);    // Bob firma Shrubbery
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		bureaucrat3.executeForm(shrubberyForm); // Charlie ejecuta Shrubbery
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		bureaucrat3.signForm(robotomyForm);     // Charlie firma Robotomy
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		bureaucrat3.executeForm(robotomyForm);  // Charlie ejecuta Robotomy
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		bureaucrat3.signForm(pardonForm);       // Charlie firma Presidential Pardon
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		bureaucrat3.executeForm(pardonForm);    // Charlie ejecuta Presidential Pardon
		std::cout << "\nDESTRUCTOR\n" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		std::cout << "\nDESTRUCTOR\n" << std::endl;
	}
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

	std::cout << "CHAT_TEST_2" << std::endl;
	std::cout << "===========" << std::endl;
	std::cout << std::endl;
	chat_test_2();
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
