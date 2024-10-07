#ifndef iter_HPP
#define iter_HPP

#include <iostream>

template <typename T>
void iter(T* array, size_t length, void (*func)(T&)) {
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}

template <typename T>
void printElement(T& element) {
	std::cout << element << " ";
}

template <typename T>
void incrementElement(T& element) {
	++element;
}

template <typename T>
void doubleElement(T& element) {
	element *= 2;
}

template <typename T>
void resetElement(T& element) {
	element = T(); // Resetea el elemento al valor por defecto
}

template <typename T>
void squareElement(T& element) {
	element *= element;
}

#endif
