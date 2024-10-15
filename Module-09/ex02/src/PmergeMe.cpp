#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe &copy) {
	this->deq = copy.deq;
	this->vec = copy.vec;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	this->deq = other.deq;
	this->vec = other.vec;
	return *this;
}

void PmergeMe::printVec(const std::string& msg, std::vector<int>& vec) {
	std::cout << msg;
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque(const std::string& msg, std::deque<int>& deq) {
	std::cout << msg;
	for (size_t i = 0; i < deq.size(); i++) {
		std::cout << deq[i] << " ";
	}
	std::cout << std::endl;
}

double PmergeMe::timeExeVec(std::vector<int>& vec) {
	clock_t start = clock();
	mergeInsertSortVector(vec);
	clock_t end = clock();
	return static_cast<double>(end - start) / CLOCKS_PER_SEC * 100;
}

double PmergeMe::timeExeDeque(std::deque<int>& deq) {
	clock_t start = clock();
	mergeInsertSortDeque(deq);
	clock_t end = clock();
	return static_cast<double>(end - start) / CLOCKS_PER_SEC * 100;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec) {
	int n = vec.size();
	if (n <= 1) return;

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> largeElements;
	std::vector<int> restElements;

	for (int i = 0; i < n; i += 2) {
		if (i + 1 < n) {
			// Si hay un par, lo ordenamos
			int a = vec[i];
			int b = vec[i + 1];
			if (a > b) std::swap(a, b); // El más pequeño se pone el primero
			pairs.push_back(std::make_pair(a, b));
			largeElements.push_back(b); // Guardamos el más grande
		} else {
			// Si no hay un par, solo guardamos el elemento
			restElements.push_back(vec[i]);
		}
	}

	// Ordenar los elementos más grandes de cada par
	std::sort(largeElements.begin(), largeElements.end());

	// Insertar los elementos mas pequeños
	for (size_t i = 0; i < pairs.size(); ++i) {
		int small = pairs[i].first;
		// Insertar e la posición adecuada
		std::vector<int>::iterator position = std::lower_bound(largeElements.begin(), largeElements.end(), small);
		largeElements.insert(position, small);
	}

	// Si hay elementos restantes los insertamos tambien
	for (size_t i = 0; i  < restElements.size(); ++i) {
		int element = restElements[i];
		std::vector<int>::iterator position = std::lower_bound(largeElements.begin(), largeElements.end(), element);
		largeElements.insert(position, element);
	}

	// Asignar el resultado a la secuencia iriginal
	vec = largeElements;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq) {
	int n = deq.size();
	if (n <= 1) return;

	std::deque<std::pair<int, int> > pairs;
	std::deque<int> largeElements;
	std::deque<int> restElements;

	for (int i = 0; i < n; i += 2) {
		if (i + 1 < n) {
			// Si hay un par, lo ordenamos
			int a = deq[i];
			int b = deq[i + 1];
			if (a > b) std::swap(a, b); // El más pequeño se pone el primero
			pairs.push_back(std::make_pair(a, b));
			largeElements.push_back(b); // Guardamos el más grande
		} else {
			// Si no hay un par, solo guardamos el elemento
			restElements.push_back(deq[i]);
		}
	}

	// Ordenar los elementos más grandes de cada par
	std::sort(largeElements.begin(), largeElements.end());

	// Insertar los elementos mas pequeños
	for (size_t i = 0; i < pairs.size(); ++i) {
		int small = pairs[i].first;
		// Insertar e la posición adecuada
		std::deque<int>::iterator position = std::lower_bound(largeElements.begin(), largeElements.end(), small);
		largeElements.insert(position, small);
	}

	// Si hay elementos restantes los insertamos tambien
	for (size_t i = 0; i  < restElements.size(); ++i) {
		int element = restElements[i];
		std::deque<int>::iterator position = std::lower_bound(largeElements.begin(), largeElements.end(), element);
		largeElements.insert(position, element);
	}

	// Asignar el resultado a la secuencia iriginal
	deq = largeElements;
}
