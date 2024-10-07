#include "../inc/Array.hpp"

void simple_test() {
	// Prueba de creación de un array vacío
	Array<int> emptyArray;
	std::cout << "Size of empty array: " << emptyArray.size() << std::endl; // Debería ser 0

	// Prueba de creación de un array con tamaño 5
	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.size(); ++i) {
		intArray[i] = (i + 1) * 10; // Inicializar elementos
	}

	std::cout << "Elements of intArray: ";
	for (unsigned int i = 0; i < intArray.size(); ++i) {
		std::cout << intArray[i] << " "; // Mostrar elementos
	}
	std::cout << std::endl;

	// Prueba de operador de copia
	Array<int> copyArray(intArray);
	std::cout << "Elements of copyArray after copying intArray: ";
	for (unsigned int i = 0; i < copyArray.size(); ++i) {
		std::cout << copyArray[i] << " "; // Mostrar elementos copiados
	}
	std::cout << std::endl;

	// Modificar copyArray y verificar que intArray no se ve afectado
	copyArray[0] = 999;
	std::cout << "After modifying copyArray[0]: " << std::endl;
	std::cout << "copyArray[0]: " << copyArray[0] << std::endl; // Debería ser 999
	std::cout << "intArray[0]: " << intArray[0] << std::endl;	// Debería seguir siendo 10

	// Prueba de operador de asignación
	Array<int> assignedArray;
	assignedArray = intArray; // Asignar intArray a assignedArray
	std::cout << "Elements of assignedArray after assignment: ";
	for (unsigned int i = 0; i < assignedArray.size(); ++i) {
		std::cout << assignedArray[i] << " "; // Mostrar elementos asignados
	}
	std::cout << std::endl;

	// Prueba de acceso fuera de límites
	try {
		std::cout << intArray[5] << std::endl; // Acceso fuera de límites
	}
	catch (const std::out_of_range &e) {
		std::cerr << "Exception: " << e.what() << std::endl; // Capturar excepción
	}
}

void testIntegerArray() {
	std::cout << "Testing Integer Array:" << std::endl;
	Array<int> intArray(5);

	for (unsigned int i = 0; i < intArray.size(); ++i) {
		intArray[i] = (i + 1) * 10; // Inicializar elementos
	}

	std::cout << "Elements of intArray: ";
	for (unsigned int i = 0; i < intArray.size(); ++i) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	// Acceso a un índice válido
	std::cout << "intArray[2]: " << intArray[2] << std::endl; // Debería ser 30

	// Prueba de acceso fuera de límites
	try {
		std::cout << intArray[5] << std::endl; // Acceso fuera de límites
	}
	catch (const std::out_of_range &e) {
		std::cerr << "Exception: " << e.what() << std::endl; // Capturar excepción
	}
}

void testDoubleArray() {
	std::cout << "\nTesting Double Array:" << std::endl;
	Array<double> doubleArray(3);

	doubleArray[0] = 1.1;
	doubleArray[1] = 2.2;
	doubleArray[2] = 3.3;

	std::cout << "Elements of doubleArray: ";
	for (unsigned int i = 0; i < doubleArray.size(); ++i) {
		std::cout << doubleArray[i] << " ";
	}
	std::cout << std::endl;

	// Acceso a un índice válido
	std::cout << "doubleArray[1]: " << doubleArray[1] << std::endl; // Debería ser 2.2
}

void testStringArray() {
	std::cout << "\nTesting String Array:" << std::endl;
	Array<std::string> strArray(4);

	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "This";
	strArray[3] = "Is a Test";

	std::cout << "Elements of strArray: ";
	for (unsigned int i = 0; i < strArray.size(); ++i) {
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;

	// Acceso a un índice válido
	std::cout << "strArray[3]: " << strArray[3] << std::endl; // Debería ser "Is a Test"
}

void testCopyAndAssignment() {
	std::cout << "\nTesting Copy and Assignment:" << std::endl;
	Array<int> originalArray(5);

	for (unsigned int i = 0; i < originalArray.size(); ++i) {
		originalArray[i] = (i + 1) * 100; // Inicializar elementos
	}

	// Prueba de copia
	Array<int> copyArray(originalArray);
	std::cout << "Elements of copyArray after copying originalArray: ";
	for (unsigned int i = 0; i < copyArray.size(); ++i) {
		std::cout << copyArray[i] << " ";
	}
	std::cout << std::endl;

	// Modificar copyArray y verificar que originalArray no se ve afectado
	copyArray[0] = 999;
	std::cout << "After modifying copyArray[0]: " << std::endl;
	std::cout << "copyArray[0]: " << copyArray[0] << std::endl;			// Debería ser 999
	std::cout << "originalArray[0]: " << originalArray[0] << std::endl; // Debería seguir siendo 100

	// Prueba de asignación
	Array<int> assignedArray;
	assignedArray = originalArray; // Asignar originalArray a assignedArray
	std::cout << "Elements of assignedArray after assignment: ";
	for (unsigned int i = 0; i < assignedArray.size(); ++i) {
		std::cout << assignedArray[i] << " ";
	}
	std::cout << std::endl;

	// Modificar assignedArray y verificar que originalArray no se ve afectado
	assignedArray[2] = 888;
	std::cout << "After modifying assignedArray[2]: " << std::endl;
	std::cout << "assignedArray[2]: " << assignedArray[2] << std::endl; // Debería ser 888
	std::cout << "originalArray[2]: " << originalArray[2] << std::endl; // Debería seguir siendo 300
}

void big_test() {
	testIntegerArray();
	testDoubleArray();
	testStringArray();
	testCopyAndAssignment();
}

int main() {
	std::cout << "-----SIMPLE TEST-----\n"
			  << std::endl;
	simple_test();
	std::cout << "\n"
			  << std::endl;
	std::cout << "-----BIG TEST-----\n"
			  << std::endl;
	big_test();
	std::cout << "\n"
			  << std::endl;
	return 0;
}
