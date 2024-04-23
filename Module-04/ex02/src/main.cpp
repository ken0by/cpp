#include "../inc/AAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main()
{
	// Crear objetos de Dog y Cat
	Dog dog;
	Cat cat;
	std::cout << std::endl;
	// Llamar a la función makeSound de cada objeto
	std::cout << "Dog says: ";
	dog.makeSound();
	std::cout << std::endl;
	std::cout << "Cat says: ";
	cat.makeSound();
	std::cout << std::endl;
	// Intentar crear un objeto de Animal (lo cual debería ser imposible)
	// AAnimal animal; // Esto dará un error de compilación
	std::cout << "DESTRUCTOR" << std::endl;
	return 0;
}
