#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cstdlib>

class PmergeMe {
	private:

	public:
		std::list<int> _myList;
		std::vector<int> _myVec;
		PmergeMe();
		~PmergeMe();

		PmergeMe(PmergeMe& copy);
		PmergeMe &operator=(const PmergeMe& other);

		double numsToContainers(std::string nums);
		double sortVec();
		double sortList();
};

#endif
