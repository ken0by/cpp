#include "../inc/PmergeMe.hpp"

bool checkDuplicate(std::vector<int>& vec) {
	std::set<int> nb;

	for (size_t i = 0; i < vec.size(); ++i) {
		// Intentamos insertar el numero en el set
		if (!nb.insert(vec[i]).second){
			// Si el numero esta repetido muestra el mensaje de error
			std::cerr << "Error: Number " << vec[i] << " is duplicate" << std::endl;
			return true;
		}
	}
	return false;
}

bool checkArg(const std::string& arg) {
	for (size_t i = 0; i < arg.length(); ++i) {
		if (!isdigit(arg[i]))
			return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	PmergeMe sort;
	std::vector<int> vec;
	std::deque<int> deq;

	if (argc < 2) {
		std::cerr << "Error: No input provided" << std::endl;
		return 1;
	}

	for (int i = 1; i < argc; ++i) {
		if (!checkArg(argv[i])) {
			std::cerr << "Error: Invalid argument: " << argv[i] << std::endl;
			return 1;
		}
		int num = std::atoi(argv[i]);
		vec.push_back(num);
		deq.push_back(num);
	}

	if (checkDuplicate(vec))
		return 1;

	// Mostrar secuencia original
	sort.printVec("Before: ", vec);

	// Medir y mostrar el tiempo de ejecución del vector
	double timeVec = sort.timeExeVec(vec);
	sort.printVec("After: ", vec);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::[..] : " << timeVec << " us" << std::endl;

	// Medir y mostrar el tiempo de ejecución del deque
	double timeDeq = sort.timeExeDeque(deq);
	std::cout << "Time to process a range of " << deq.size() << " elements with std::[..] : " << timeDeq << " us" << std::endl;

	return 0;
}
