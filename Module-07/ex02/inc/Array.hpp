#ifndef Array_HPP
#define Array_HPP

#include <iostream>
#include <exception>

template <typename T>

class Array {
private:
	T *array;
	unsigned int m_size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array<T> &other);
	Array &operator=(const Array<T> &other);
	~Array();

	T& operator[](unsigned int index); // Operador de subíndice
	const T& operator[](unsigned int index) const; // Operador de subíndice (const)
	unsigned int size() const; // Tamaño del array
};

// Implementación del constructor sin parámetros
template <typename T>
Array<T>::Array() : array(NULL), m_size(0) {
	std::cout << "Array default constructor called!" << std::endl;
}

// Implementación del constructor con tamaño
template <typename T>
Array<T>::Array(unsigned int n) : m_size(n) {
	array = new T[n]; // Asignación de memoria
	std::cout << "Array constructor called!" << std::endl;
}

// Implementación del constructor de copia
template <typename T>
Array<T>::Array(const Array<T> &other) : m_size(other.m_size) {
	array = new T[m_size]; // Asignación de memoria
	for (unsigned int i = 0; i < m_size; ++i) {
		array[i] = other.array[i]; // Copia de elementos
	}
	std::cout << "Array copy constructor called!" << std::endl;
}

// Implementación del operador de asignación
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other) {					 // Autocontrol
		delete[] array; // Liberar memoria existente
		m_size = other.m_size;
		array = new T[m_size]; // Asignación de memoria
		for (unsigned int i = 0; i < m_size; ++i) {
			array[i] = other.array[i]; // Copia de elementos
		}
	}
	return *this;
}

// Implementación del destructor
template <typename T>
Array<T>::~Array() {
	delete[] array; // Liberar memoria
	std::cout << "Array destructor called!" << std::endl;
}

// Implementación del operador de subíndice
template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= m_size) {
		throw std::out_of_range("Index out of range");
	}
	return array[index];
}

// Implementación del operador de subíndice (const)
template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= m_size) {
		throw std::out_of_range("Index out of range");
	}
	return array[index];
}

// Implementación de la función m_size()
template <typename T>
unsigned int Array<T>::size() const {
	return m_size;
}

#endif
