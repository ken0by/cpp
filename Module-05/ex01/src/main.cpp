#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

void chat_test()
{
	try
	{
		Bureaucrat alice("Alice", 2);
		Form formA("Form A", 1, 10);

		std::cout << alice << std::endl;
		std::cout << formA << std::endl;

		alice.executeForm(formA);
		std::cout << formA << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void chat_test_2()
{
	// Prueba 1: Bureaucrat con un rango suficiente para firmar el formulario
	try
	{
		Bureaucrat alice("Alice", 2); // Grado 2
		Form formA("Form A", 3, 10);  // Grado necesario para firmar: 3, ejecutar: 10

		std::cout << alice << std::endl;
		std::cout << formA << std::endl;

		alice.executeForm(formA); // Alice puede firmar porque tiene grado 2 (mejor que 3)
		std::cout << formA << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";

	// Prueba 2: Bureaucrat con un rango insuficiente para firmar
	try
	{
		Bureaucrat bob("Bob", 5);	 // Grado 5
		Form formB("Form B", 2, 10); // Grado necesario para firmar: 2, ejecutar: 10

		std::cout << bob << std::endl;
		std::cout << formB << std::endl;

		bob.executeForm(formB); // Bob no puede firmar porque su grado es 5 (se requiere 2)
		std::cout << formB << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";

	// Prueba 3: Intentar firmar un formulario ya firmado
	try
	{
		Bureaucrat charlie("Charlie", 1); // Grado 1 (máximo)
		Form formC("Form C", 5, 20);	  // Grado necesario para firmar: 5, ejecutar: 20

		std::cout << charlie << std::endl;
		std::cout << formC << std::endl;

		charlie.executeForm(formC); // Charlie puede firmar (grado 1 es suficiente)
		std::cout << formC << std::endl;

		// Intentamos firmar de nuevo el mismo formulario
		charlie.executeForm(formC); // No debería causar problemas, pero no tiene sentido firmarlo dos veces
		std::cout << formC << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";

	// Prueba 4: Formulario con grados fuera de rango
	try
	{
		Bureaucrat dave("Dave", 10);
		// Formulario con grados inválidos (mayor que 150 o menor que 1)
		Form formD("Form D", 0, 151); // Esto lanzará una excepción inmediatamente
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception while creating form: " << e.what() << std::endl;
	}

	std::cout << "\n";

	// Prueba 5: Grado bajo que intenta firmar un formulario de alta exigencia
	try
	{
		Bureaucrat eve("Eve", 150); // Grado más bajo (150)
		Form formE("Form E", 1, 1); // Grado necesario para firmar: 1, ejecutar: 1 (más alto)

		std::cout << eve << std::endl;
		std::cout << formE << std::endl;

		eve.executeForm(formE); // Eve no puede firmar, su rango es demasiado bajo
		std::cout << formE << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n";

	// Prueba 6: Creación de un Bureaucrat con rango inválido
	try
	{
		// Bureaucrat con rango inválido (menor que 1)
		Bureaucrat invalidBureaucrat("Invalid Bureaucrat", 0); // Esto lanzará una excepción
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception while creating bureaucrat: " << e.what() << std::endl;
	}
}

int main()
{
	std::cout << "CHAT_TEST" << std::endl;
	chat_test();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "CHAT_TEST_2" << std::endl;
	chat_test_2();
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
