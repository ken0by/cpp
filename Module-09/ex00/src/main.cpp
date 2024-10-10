#include "../inc/BitcoinExchange.hpp"

bool isValidValue(const std::string &value) {
	char *end;
	double val = std::strtod(value.c_str(), &end);
	if (val < 0) std::cerr << "Error: not a positive number." << std::endl;
	if (val > 1000) std::cerr << "Error: too large a number." << std::endl;
	return (end != value.c_str() && val >= 0 && val <= 1000);
}

void simple_test(std::string file) {
	BitcoinExchange bitcoin("data.csv");
	std::ifstream inputFile(file.c_str());

	if (!inputFile.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string line;
	bool firstLine = true;
	while (std::getline(inputFile, line)) {
		if (firstLine) {
			firstLine = false;
			continue;
		}
		std::istringstream iss(line);
		std::string date, value;

		if (std::getline(iss, date, '|') && std::getline(iss, value)) {
			date.erase(0, date.find_first_not_of(" \t"));
			value.erase(0, value.find_first_not_of(" \t"));

			if (!bitcoin.isValidDate(date)) {
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}
			if (!isValidValue(value)) {
				continue;
			}

			double val = std::atof(value.c_str());
			double price = bitcoin.getPriceForDate(date);

			if (price == -1) {
				std::cerr << "Error: no price available for date " << date << std::endl;
				continue;
			}

			double totalValue = val * price;
			std::cout << date << " => " << val << " = " << totalValue << std::endl;
		} else {
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}

	inputFile.close();
}

bool isTxtFile(const char* filename) {
	const char* dot = strrchr(filename, '.');
	if (!dot || dot == filename) {
		return false;
	}
	return strcmp(dot, ".txt") == 0;
}

bool fileExists(const char* filename) {
	struct stat buffer;
	return (stat(filename, &buffer) == 0);
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: missing index.txt." << std::endl;
		return 1;
	}

	const char* filePath = argv[1];
	if (!fileExists(filePath)) {
		std::cerr << "Error: El archivo no existe." << std::endl;
		return 1;
	}
	if (!isTxtFile(filePath)) {
		std::cerr << "Error: El archivo debe ser un archivo .txt." << std::endl;
		return 1;
	}

	std::cout << "-----TEST-----\n" << std::endl;
	simple_test(argv[1]);
	std::cout << "\n" << std::endl;
	return 0;
}
