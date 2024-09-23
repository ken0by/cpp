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
}

int main()
{
	chat_test();
	my_test();
	return 0;
}
