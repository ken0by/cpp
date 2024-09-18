#include "../inc/Bureaucrat.hpp"

void chat_test(){
	try{
		// Creación de un objeto Bureaucrat
		Bureaucrat bureaucrat("Alice", 2);
		std::cout << bureaucrat << std::endl;

		// Incrementa el grado (debería ser válido)
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		// Intentar incrementar el grado por encima de 1 (lanzará excepción)
		bureaucrat.incrementGrade(); // Esto lanzará una excepción
	}
	catch (std::exception &e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try{
		// Creación de un objeto con grado demasiado bajo
		Bureaucrat bureaucrat2("Bob", 151); // Esto lanzará una excepción
	}
	catch (std::exception &e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void my_test(){
	Bureaucrat mateo("mateo", 150);
	std::cout << &mateo;

	std::cout << std::endl;

	Bureaucrat low("low", 1);
	std::cout << &low;
	low.incrementGrade();
	std::cout << &low;

	std::cout << std::endl;

	Bureaucrat high("high", 150);
	std::cout << &high;
	high.decrementGrade();
	std::cout << &high;

	std::cout << std::endl;

	Bureaucrat a("other", 1150);
	std::cout << &a;
	Bureaucrat b("other", -100);
	std::cout << &b;

	std::cout << std::endl;

	Bureaucrat *c = new Bureaucrat ("pepe", 0);
	std::cout << c;

	std::cout << std::endl;

	delete c;
}

int main(){
	// chat_test();
	my_test();
	return 0;
}
