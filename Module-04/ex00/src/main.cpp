#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "WRONG ANIMALS" << std::endl;
	std::cout << std::endl;

	const WrongAnimal *wrong1 = new WrongAnimal();
	const WrongAnimal *wrong2 = new WrongCat();
	const WrongAnimal *wrong3 = new WrongCat();

	std::cout << wrong1->getType() << " " << std::endl;
	std::cout << wrong2->getType() << " " << std::endl;

	wrong1->makeSound();
	wrong2->makeSound();
	wrong3->makeSound();

	delete wrong1;
	delete wrong2;
	delete wrong3;

	// std::cout << "Mixing with wrong animals should not compile => ERROR" << std::endl;
	// const Animal* doggy = new WrongCat();
	// std::cout << "Type [" << cat->getType() << "] " << std::endl;
	// doggy->makeSound();
	// delete doggy;

	return 0;
}
