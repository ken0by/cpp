#include "../inc/easyfind.hpp"

void simple_test()
{
	std::vector<int> vec; // Declaración del vector
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found value: " << *it << std::endl; // Debería imprimir 3

		it = easyfind(vec, 6);
		std::cout << "Found value: " << *it << std::endl; // No debería llegar aquí
	}
	catch (const ValueNotFoundException &e)
	{
		std::cout << e.what() << std::endl; // Manejo de la excepción
	}

	// Ahora para std::list
	std::list<int> lst; // Declaración de la lista
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	try
	{
		std::list<int>::iterator itList = easyfind(lst, 20);
		std::cout << "Found value: " << *itList << std::endl; // Debería imprimir 20

		itList = easyfind(lst, 100);
		std::cout << "Found value: " << *itList << std::endl; // No debería llegar aquí
	}
	catch (const ValueNotFoundException &e)
	{
		std::cout << e.what() << std::endl; // Manejo de la excepción
	}
}

void big_test()
{
	// Vector de enteros
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	std::cout << "Testing vector<int>..." << std::endl;

	try
	{
		std::cout << "Searching for 3: ";
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found value: " << *it << std::endl; // Debería imprimir 3
	}
	catch (const ValueNotFoundException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Searching for 6: ";
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << "Found value: " << *it << std::endl; // No debería llegar aquí
	}
	catch (const ValueNotFoundException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl; // Debería imprimir el mensaje de excepción
	}

	// Lista de enteros
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);
	std::cout << "\nTesting list<int>..." << std::endl;

	try
	{
		std::cout << "Searching for 20: ";
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "Found value: " << *it << std::endl; // Debería imprimir 20
	}
	catch (const ValueNotFoundException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Searching for 100: ";
		std::list<int>::iterator it = easyfind(lst, 100);
		std::cout << "Found value: " << *it << std::endl; // No debería llegar aquí
	}
	catch (const ValueNotFoundException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl; // Debería imprimir el mensaje de excepción
	}

	// Conjunto de enteros
	std::set<int> s;
	s.insert(5);
	s.insert(10);
	s.insert(15);
	s.insert(20);
	s.insert(25);
	std::cout << "\nTesting set<int>..." << std::endl;

	try
	{
		std::cout << "Searching for 15: ";
		std::set<int>::iterator it = easyfind(s, 15);
		std::cout << "Found value: " << *it << std::endl; // Debería imprimir 15
	}
	catch (const ValueNotFoundException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Searching for 30: ";
		std::set<int>::iterator it = easyfind(s, 30);
		std::cout << "Found value: " << *it << std::endl; // No debería llegar aquí
	}
	catch (const ValueNotFoundException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl; // Debería imprimir el mensaje de excepción
	}

	// Vector vacío
	std::vector<int> emptyVec;
	std::cout << "\nTesting empty vector..." << std::endl;

	try
	{
		std::cout << "Searching for 1: ";
		std::vector<int>::iterator it = easyfind(emptyVec, 1);
		std::cout << "Found value: " << *it << std::endl; // No debería llegar aquí
	}
	catch (const ValueNotFoundException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl; // Debería imprimir el mensaje de excepción
	}
}

int main()
{
	std::cout << "-----SIMPLE TEST-----\n" << std::endl;
	simple_test();
	std::cout << "\n" << std::endl;
	std::cout << "-----BIG TEST-----\n" << std::endl;
	big_test();
	std::cout << "\n" << std::endl;
	return 0;
}
