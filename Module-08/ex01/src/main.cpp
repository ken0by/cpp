#include "../inc/Span.hpp"

void test() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void simple_test() {
	try {
		Span sp(10000);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		// Agregar un rango de números
		std::vector<int> moreNumbers;
		moreNumbers.push_back(2);
		moreNumbers.push_back(4);
		moreNumbers.push_back(6);
		moreNumbers.push_back(8);
		moreNumbers.push_back(10);
		sp.addRange(moreNumbers.begin(), moreNumbers.end());

		std::cout << "Shortest span after range: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span after range: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void simpleTest() {
	try {
		Span sp(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
			std::cout << "Simple Test:" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void exceptionTest() {
	try {
		Span sp(3);
		sp.addNumber(5);
		sp.addNumber(3);
			std::cout << "Exception Test (shortestSpan with < 2 numbers):" << std::endl;
		sp.shortestSpan();  // Esto debería lanzar una excepción
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		Span sp(2);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(9);  // Esto debería lanzar una excepción porque excede el tamaño
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
	void largeRangeTest() {
	try {
		Span sp(10000);
			std::cout << "Adding numbers from 0 to 9999 in one call:" << std::endl;
			std::vector<int> range(10000);
		for (int i = 0; i < 10000; ++i) {
			range[i] = i;
		}
		sp.addRange(range.begin(), range.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Debería ser 1
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Debería ser 9999
		std::cout << std::endl;
		} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void randomTest() {
	try {
		Span sp(10000);
		std::srand(static_cast<unsigned int>(std::time(0)));  // Inicializa el generador de números aleatorios
			std::cout << "Adding 10,000 random numbers:" << std::endl;
		for (int i = 0; i < 10000; ++i) {
			sp.addNumber(std::rand() % 100000);  // Números aleatorios entre 0 y 99999
		}
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << std::endl;
		} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void rangeInsertionTest() {
	try {
		Span sp(100);
		std::vector<int> numbers;
		for (int i = 1; i <= 100; ++i) {
			numbers.push_back(i);
	}

		sp.addRange(numbers.begin(), numbers.end());

		std::cout << "Range Insertion Test:" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Debería ser 1
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Debería ser 99
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void big_test() {
	std::cout << "=== Simple Test ===" << std::endl;
	simpleTest();
	std::cout << "=== Exception Test ===" << std::endl;
	exceptionTest();
	std::cout << "=== Large Range Test ===" << std::endl;
	largeRangeTest();
	std::cout << "=== Random Test ===" << std::endl;
	randomTest();
	std::cout << "=== Range Insertion Test ===" << std::endl;
	rangeInsertionTest();
}

int main() {
	std::cout << "-----SUBJECT TEST-----\n" << std::endl;
	test();
	std::cout << "\n" << std::endl;
	std::cout << "-----SIMPLE TEST-----\n" << std::endl;
	simple_test();
	std::cout << "\n" << std::endl;
	std::cout << "-----BIG TEST-----\n" << std::endl;
	big_test();
	std::cout << "\n" << std::endl;
	return 0;
}
