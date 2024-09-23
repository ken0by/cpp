#include "../inc/Bureaucrat.hpp"

void chat_test()
{
	try
	{
		Bureaucrat bureaucrat("Alice", 2);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat2("Bob", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void chat_test_2()
{
	// Caso 1: Crear un burócrata con un rango válido y luego intentar incrementar el rango más allá del límite
	try
	{
		Bureaucrat bureaucrat("Alice", 2);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		// Este incremento debería lanzar una excepción, ya que el rango máximo es 1
		bureaucrat.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Caso 2: Crear un burócrata con un rango inválido (demasiado bajo)
	try
	{
		Bureaucrat bureaucrat2("Bob", 151); // Debería lanzar una excepción
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Caso 3: Crear un burócrata con un rango válido y luego intentar disminuir el rango por debajo del límite
	try
	{
		Bureaucrat bureaucrat3("Charlie", 149);
		std::cout << bureaucrat3 << std::endl;

		bureaucrat3.decrementGrade(); // Decrementa a 150, aún válido
		std::cout << bureaucrat3 << std::endl;

		// Este decremento debería lanzar una excepción, ya que el rango mínimo es 150
		bureaucrat3.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Caso 4: Crear un burócrata con un rango inválido (demasiado alto)
	try
	{
		Bureaucrat bureaucrat4("Dave", 0); // Debería lanzar una excepción
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void my_test()
{
	try
	{
		Bureaucrat mateo("mateo", 150);
		std::cout << mateo << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat low("low", 1);
		std::cout << low << std::endl;
		low.incrementGrade(); // Esto lanzará una excepción
		std::cout << low << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat high("high", 150);
		std::cout << high << std::endl;
		high.decrementGrade(); // Esto lanzará una excepción
		std::cout << high << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat a("other", 1150); // Esto lanzará una excepción
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b("other", -100);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat *c = new Bureaucrat("pepe", 0);
		std::cout << c << std::endl;
		delete c;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void try_test()
{
	try
	{
		Bureaucrat mateo("mateo", 150);
		std::cout << mateo << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat low("low", 150);
		std::cout << low << std::endl;
		low.decrementGrade();
		std::cout << low << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat high("high", 1);
		std::cout << high << std::endl;
		high.incrementGrade();
		std::cout << high << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat a("other", 1150);
		std::cout << a << std::endl;
		Bureaucrat b("other", -100);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat *c = new Bureaucrat("pepe", 0);
		std::cout << c << std::endl;
		delete c;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	// std::cout << "CHAT_TEST" << std::endl;
	// chat_test();
	// std::cout << std::endl;
	// std::cout << std::endl;
	std::cout << "CHAT_TEST_2" << std::endl;
	chat_test_2();
	std::cout << std::endl;
	std::cout << std::endl;
	// std::cout << "MY_TEST" << std::endl;
	// my_test();
	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << "TRY_TEST" << std::endl;
	// try_test();
	// std::cout << std::endl;
	return 0;
}
