#include "../inc/iter.hpp"

void simple_test() {
	// Prueba con un array de enteros
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original int array: ";
	iter(intArray, intLength, printElement);
	std::cout << std::endl;

	iter(intArray, intLength, incrementElement);

	std::cout << "Incremented int array: ";
	iter(intArray, intLength, printElement);
	std::cout << std::endl;

	// Prueba con un array de doubles
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Original double array: ";
	iter(doubleArray, doubleLength, printElement);
	std::cout << std::endl;

	iter(doubleArray, doubleLength, incrementElement);

	std::cout << "Incremented double array: ";
	iter(doubleArray, doubleLength, printElement);
	std::cout << std::endl;
}

void big_test() {
	// Prueba con un array de enteros
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original int array: ";
	iter(intArray, intLength, printElement);
	std::cout << std::endl;

	iter(intArray, intLength, incrementElement);
	std::cout << "Incremented int array: ";
	iter(intArray, intLength, printElement);
	std::cout << std::endl;

	iter(intArray, intLength, doubleElement);
	std::cout << "Doubled int array: ";
	iter(intArray, intLength, printElement);
	std::cout << std::endl;

	iter(intArray, intLength, squareElement);
	std::cout << "Squared int array: ";
	iter(intArray, intLength, printElement);
	std::cout << std::endl;

	iter(intArray, intLength, resetElement);
	std::cout << "Reset int array: ";
	iter(intArray, intLength, printElement);
	std::cout << std::endl;

	// Prueba con un array de doubles
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Original double array: ";
	iter(doubleArray, doubleLength, printElement);
	std::cout << std::endl;

	iter(doubleArray, doubleLength, incrementElement);
	std::cout << "Incremented double array: ";
	iter(doubleArray, doubleLength, printElement);
	std::cout << std::endl;

	iter(doubleArray, doubleLength, doubleElement);
	std::cout << "Doubled double array: ";
	iter(doubleArray, doubleLength, printElement);
	std::cout << std::endl;

	iter(doubleArray, doubleLength, squareElement);
	std::cout << "Squared double array: ";
	iter(doubleArray, doubleLength, printElement);
	std::cout << std::endl;

	iter(doubleArray, doubleLength, resetElement);
	std::cout << "Reset double array: ";
	iter(doubleArray, doubleLength, printElement);
	std::cout << std::endl;

	// Prueba con un array de caracteres
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charLength = sizeof(charArray) / sizeof(charArray[0]);

	std::cout << "Original char array: ";
	iter(charArray, charLength, printElement);
	std::cout << std::endl;

	iter(charArray, charLength, incrementElement); // Incrementar caracteres
	std::cout << "Incremented char array: ";
	iter(charArray, charLength, printElement);
	std::cout << std::endl;

	iter(charArray, charLength, resetElement);
	std::cout << "Reset char array: ";
	iter(charArray, charLength, printElement);
	std::cout << std::endl;

	// Prueba con un array de cadenas
	std::string strArray[] = {"Hello", "World", "C++", "Templates"};
	size_t strLength = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "Original string array: ";
	iter(strArray, strLength, printElement);
	std::cout << std::endl;

	iter(strArray, strLength, resetElement);
	std::cout << "Reset string array: ";
	iter(strArray, strLength, printElement);
	std::cout << std::endl;
}

int main() {
	std::cout << "-----SIMPLE TEST-----\n" << std::endl;
	simple_test();
	std::cout << "\n" << std::endl;
	std::cout << "-----BIG TEST-----\n" << std::endl;
	big_test();
	std::cout << "\n" << std::endl;
	return 0;
}
