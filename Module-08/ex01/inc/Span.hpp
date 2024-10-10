#ifndef Span_HPP
#define Span_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <climits>
#include <ctime>

class Span
{
	private:
		std::vector<int> _number;
		unsigned int _maxsize;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		template <typename It>
		void addRange(It begin, It end) {
			if (static_cast<unsigned long>(std::distance(begin, end)) > _maxsize - _number.size())
				throw std::out_of_range("Se excede el tamaño máximo del Span.");
			_number.insert(_number.end(), begin, end);
		}
};

#endif
