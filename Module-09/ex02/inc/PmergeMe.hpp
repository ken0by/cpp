#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <stdexcept>
#include <algorithm>

class PmergeMe {
	private:

	public:
		std::deque<int> deq;
		std::vector<int> vec;

		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe& copy);
		PmergeMe &operator=(const PmergeMe& other);

		// Funciones para ordenar usando vectores y deques
		void mergeInsertSortVector(std::vector<int>& vec);
		void mergeInsertSortDeque(std::deque<int>& deq);

		// Función para medir el tiempo de ejecución
		double timeExeVec(std::vector<int>& vec);
		double timeExeDeque(std::deque<int>& deq);

		// Funciones para mostrar la secuencia antes y después de ordenar
		void printVec(const std::string& msg, std::vector<int>& vec);
		void printDeque(const std::string& msg, std::deque<int>& deq);
};

#endif
