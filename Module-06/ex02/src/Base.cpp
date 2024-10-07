#include "../inc/Base.hpp"

Base::~Base() {
	std::cout << "Base destructor called!" << std::endl;
}

Base *generate() {
	srand(static_cast<unsigned>(time(0))); // Inicializa la semilla del random solo una vez
	int randomValue = rand() % 3;		   // Valor aleatorio entre 0 y 2

	if (randomValue == 0) {
		std::cout << "Generated: A" << std::endl;
		return new A();
	} else if (randomValue == 1) {
		std::cout << "Generated: B" << std::endl;
		return new B();
	} else {
		std::cout << "Generated: C" << std::endl;
		return new C();
	}
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "Type: A" << std::endl;
	} else if (dynamic_cast<B *>(p)) {
		std::cout << "Type: B" << std::endl;
	} else if (dynamic_cast<C *>(p)) {
		std::cout << "Type: C" << std::endl;
	} else {
		std::cout << "Unknown Type" << std::endl;
	}
}

void identify(Base &p) {
	 // Intentamos hacer el dynamic_cast y comprobamos si el resultado es nulo
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;
		return;
	} catch (...) {}

	// En caso de que no sea A, B ni C, no deberíamos llegar aquí
	std::cout << "Unknown type" << std::endl;
}
