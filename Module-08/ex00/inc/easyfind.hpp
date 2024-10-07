#ifndef easyfind_HPP
#define easyfind_HPP

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <exception>

class ValueNotFoundException : public std::exception {
public:
	const char* what() const throw() {
		return "Value not found in the container.";
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw ValueNotFoundException();
	}
	return it;
}

#endif

