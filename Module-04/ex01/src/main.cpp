#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main()
{
	std::cout << "EXAMPLE EXE" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
	std::cout << std::endl;
	//system("leaks -q brain");
	std::cout << std::endl;

	std::cout << "\nCHECK DEEP COPY\n" << std::endl;
	Dog rex;
	Cat fa;

	Dog & rex_ref = rex;
	Cat & fa_ref = fa;

	std::cout << "\ncreating copies" << std::endl;
	Dog rex_cpy(rex_ref);
	Cat fa_cpy(fa_ref);

	Dog & rex_cpy_ref = rex_cpy;
	Cat & fa_cpy_ref = fa_cpy;

	std::cout << "\ncompairing rex" << std::endl;
	rex.compare(rex_cpy_ref);
	std::cout << "\ncompairing fa" << std::endl;
	fa.compare(fa_cpy_ref);
	std::cout << std::endl;

	std::cout << "\nARRAY\n" << std::endl;
	const Animal *(animals[4]);

	for (int i = 0; i < 2; i++){
		animals[i] = new Dog();
	}
	std::cout << std::endl;

	for (int i = 2; i < 4; i++){
		animals[i] = new Cat();
	}
	std::cout << std::endl;

	for (int i = 0; i < 4; i++){
		animals[i]->makeSound();
	}
	std::cout << std::endl;
	std::cout << "Destructor" << std::endl;
	std::cout << "\nDog\n" << std::endl;
	for (int i = 0; i < 2; i++){
		delete animals[i];
	}
	std::cout << std::endl;
	std::cout << "\nCat\n" << std::endl;
	for (int i = 2; i < 4; i++){
		delete animals[i];
	}
	std::cout << std::endl;
	std::cout << "All done!" << std::endl;
	//system("leaks -q brain");
	return 0;
}
