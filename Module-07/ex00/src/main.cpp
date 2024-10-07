#include "../inc/whatever.hpp"

void subject_test() {
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

void simple_test() {
	int x = 5, y = 10;

	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

	std::cout << "Min of x and y: " << ::min(x, y) << std::endl;
	std::cout << "Max of x and y: " << ::max(x, y) << std::endl;

	double a = 5.5, b = 10.1;
	std::cout << "Min of a and b: " << ::min(a, b) << std::endl;
	std::cout << "Max of a and b: " << ::max(a, b) << std::endl;

	std::string str1 = "apple", str2 = "orange";
	std::cout << "Min of str1 and str2: " << ::min(str1, str2) << std::endl;
	std::cout << "Max of str1 and str2: " << ::max(str1, str2) << std::endl;
}

void big_test() {
	// Casos con enteros
	int a = 42;
	int b = 10;

	std::cout << "Before swap (int): a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap (int): a = " << a << ", b = " << b << std::endl;
	std::cout << "Min of a and b: " << ::min(a, b) << std::endl;
	std::cout << "Max of a and b: " << ::max(a, b) << std::endl;

	// Casos con flotantes
	float c = 3.14f;
	float d = 2.71f;

	std::cout << "\nBefore swap (float): c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "After swap (float): c = " << c << ", d = " << d << std::endl;
	std::cout << "Min of c and d: " << ::min(c, d) << std::endl;
	std::cout << "Max of c and d: " << ::max(c, d) << std::endl;

	// Casos con dobles
	double e = 9.81;
	double f = 8.88;

	std::cout << "\nBefore swap (double): e = " << e << ", f = " << f << std::endl;
	swap(e, f);
	std::cout << "After swap (double): e = " << e << ", f = " << f << std::endl;
	std::cout << "Min of e and f: " << ::min(e, f) << std::endl;
	std::cout << "Max of e and f: " << ::max(e, f) << std::endl;

	// Casos con caracteres
	char g = 'x';
	char h = 'y';

	std::cout << "\nBefore swap (char): g = " << g << ", h = " << h << std::endl;
	swap(g, h);
	std::cout << "After swap (char): g = " << g << ", h = " << h << std::endl;
	std::cout << "Min of g and h: " << ::min(g, h) << std::endl;
	std::cout << "Max of g and h: " << ::max(g, h) << std::endl;

	// Casos con strings
	std::string i = "banana";
	std::string j = "apple";

	std::cout << "\nBefore swap (string): i = " << i << ", j = " << j << std::endl;
	swap(i, j);
	std::cout << "After swap (string): i = " << i << ", j = " << j << std::endl;
	std::cout << "Min of i and j: " << ::min(i, j) << std::endl;
	std::cout << "Max of i and j: " << ::max(i, j) << std::endl;

	// Casos de igualdad
	int k = 10;
	int l = 10;

	std::cout << "\nBefore swap (equal int): k = " << k << ", l = " << l << std::endl;
	swap(k, l);
	std::cout << "After swap (equal int): k = " << k << ", l = " << l << std::endl;
	std::cout << "Min of k and l: " << ::min(k, l) << std::endl;
	std::cout << "Max of k and l: " << ::max(k, l) << std::endl;
}

int main() {
	std::cout << "-----SUBJECT TEST-----\n" << std::endl;
	subject_test();
	std::cout << "\n" << std::endl;
	std::cout << "-----SIMPLE TEST-----\n" << std::endl;
	simple_test();
	std::cout << "\n" << std::endl;
	std::cout << "-----BIG TEST-----\n" << std::endl;
	big_test();
	std::cout << "\n" << std::endl;
	return 0;
}
