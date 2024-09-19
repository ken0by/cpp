#include "../inc/Bureaucrat.hpp"

void chat_test(){
	try{
		Bureaucrat bureaucrat("Alice", 2);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
	}
	catch (std::exception &e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try{
		Bureaucrat bureaucrat2("Bob", 151);
	}
	catch (std::exception &e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void my_test(){
	Bureaucrat mateo("mateo", 150);
	std::cout << mateo << std::endl;

	std::cout << std::endl;

	Bureaucrat low("low", 1);
	std::cout << low << std::endl;
	low.incrementGrade();
	std::cout << low << std::endl;

	std::cout << std::endl;

	Bureaucrat high("high", 150);
	std::cout << high << std::endl;
	high.decrementGrade();
	std::cout << high << std::endl;

	std::cout << std::endl;

	Bureaucrat a("other", 1150);
	std::cout << a << std::endl;
	Bureaucrat b("other", -100);
	std::cout << b << std::endl;

	std::cout << std::endl;

	Bureaucrat *c = new Bureaucrat ("pepe", 0);
	std::cout << c << std::endl;

	std::cout << std::endl;

	delete c;
}

int main(){
	// chat_test();
	my_test();
	return 0;
}
