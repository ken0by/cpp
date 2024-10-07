#include "../inc/Base.hpp"

void simple_test() {
	// Generar un objeto aleatorio
	Base *randomBase = generate();

	// Identificar el tipo de objeto usando un puntero
	std::cout << "Identifying by pointer:" << std::endl;
	identify(randomBase);

	// Identificar el tipo de objeto usando una referencia
	std::cout << "Identifying by reference:" << std::endl;
	identify(*randomBase);

	// Limpiar la memoria
	delete randomBase;
}

void big_test() {
	// Inicializa un array de punteros a Base para almacenar múltiples objetos generados
	const int numTests = 10; // Número de pruebas para generar aleatoriamente clases derivadas
	Base *objects[numTests];

	std::cout << "=== Generating random objects ===" << std::endl;

	// Generar y almacenar varios objetos aleatorios
	for (int i = 0; i < numTests; ++i)
	{
		objects[i] = generate();
	}

	std::cout << std::endl
			  << "=== Identifying by pointer ===" << std::endl;

	// Identificar cada objeto usando punteros
	for (int i = 0; i < numTests; ++i)
	{
		std::cout << "Object " << i + 1 << ": ";
		identify(objects[i]);
	}

	std::cout << std::endl
			  << "=== Identifying by reference ===" << std::endl;

	// Identificar cada objeto usando referencias
	for (int i = 0; i < numTests; ++i)
	{
		std::cout << "Object " << i + 1 << ": ";
		identify(*objects[i]);
	}

	// Limpiar memoria
	std::cout << std::endl
			  << "=== Cleaning up ===" << std::endl;
	for (int i = 0; i < numTests; ++i)
	{
		delete objects[i];
	}

	// Pruebas adicionales: crear objetos específicos y probar las funciones
	std::cout << std::endl
			  << "=== Additional specific object tests ===" << std::endl;
	A *a = new A();
	B *b = new B();
	C *c = new C();

	std::cout << "Identifying A object by pointer: ";
	identify(a);
	std::cout << "Identifying A object by reference: ";
	identify(*a);

	std::cout << "Identifying B object by pointer: ";
	identify(b);
	std::cout << "Identifying B object by reference: ";
	identify(*b);

	std::cout << "Identifying C object by pointer: ";
	identify(c);
	std::cout << "Identifying C object by reference: ";
	identify(*c);

	// Limpiar memoria de pruebas adicionales
	delete a;
	delete b;
	delete c;
}

void test() {
	std::srand(time(NULL));

	Base* ra;
	Base* ran;
	Base* rand;
	Base* rando;
	Base* random;

	std::cout << "Identify with pointer" << std::endl;
	ra = generate();
	identify(ra);
	std::cout << std::endl;
	ran = generate();
	identify(ran);
	std::cout << std::endl;
	rand = generate();
	identify(rand);
	std::cout << std::endl;

	std::cout << "Identify with reference" << std::endl;
	rando = generate();
	identify(rando);
	std::cout << std::endl;
	random = generate();
	identify(random);

	delete ra;
	delete ran;
	delete rand;
	delete rando;
	delete random;
}

int main() {
	std::cout << "-----SIMPLE TEST-----" << std::endl;
	simple_test();
	std::cout << "\n" << std::endl;
	std::cout << "-----BIG TEST-----" << std::endl;
	big_test();
	std::cout << "\n" << std::endl;
	std::cout << "-----TEST-----" << std::endl;
	test();
	std::cout << "\n" << std::endl;
	return 0;
}
