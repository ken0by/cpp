#include "../inc/Span.hpp"

Span::Span() {
	std::cout << "Span default constructor called!" << std::endl;
}

Span::Span(unsigned int N) : _maxsize(N) {
	std::cout << "Span constructor called!" << std::endl;
}

Span::Span(const Span& /*other*/) {}

Span& Span::operator=(const Span& /*other*/){
	return (*this);
}

Span::~Span() {
	std::cout << "Span destructor called!" << std::endl;
}

void Span::addNumber(int n) {
	if (_number.size() >= _maxsize)
		throw std::out_of_range("No se pueden agregar más números, el Span está lleno.");
	_number.push_back(n);
}

int Span::shortestSpan() {
	if (_number.size() < 2)
		throw std::logic_error("No hay suficientes números para calcular el span.");
	std::vector<int> sorted = _number;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = INT_MAX;
	for (size_t i = 1; i < sorted.size(); ++i) {
		minSpan = std::min(minSpan, sorted[i] - sorted[i - 1]);
	}
	return minSpan;
}

 int Span::longestSpan() {
	if (_number.size() < 2)
		throw std::logic_error("No hay suficientes números para calcular el span.");
	int min = *std::min_element(_number.begin(), _number.end());
	int max = *std::max_element(_number.begin(), _number.end());
	return max - min;
}
