#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "BitcoinExchange default constructor called!" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string &filename) {
	loadPrices(filename);
	std::cout << "BitcoinExchange constructor called!" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& /*other*/) {
	std::cout << "BitcoinExchange copy constructor called!" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& /*other*/){
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "BitcoinExchange destructor called!" << std::endl;
}

void BitcoinExchange::loadPrices(const std::string& filename) {
	std::ifstream pricesFile(filename.c_str());
	std::string line;
	bool firstLine = true;
	while (std::getline(pricesFile, line)) {
		if (firstLine) {
			firstLine = false;
			continue;
		}
		std::istringstream iss(line);
		std::string date;
		double price;

		if (std::getline(iss, date, ',') && (iss >> price)) {
			if (isValidDate(date) && price >= 0 && price <= 2147483647) {
				prices[date] = price;
			} else {
				std::cerr << "Error: bad input => " << date << " | " << price << std::endl;
			}
		} else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
}

double BitcoinExchange::getPriceForDate(const std::string &date) {
	std::string closestDate = "";
	double closestPrice = 0.0;

	 for (std::map<std::string, double>::const_iterator it = prices.begin(); it != prices.end(); ++it) {
		if (it->first <= date) {
			closestDate = it->first;
			closestPrice = it->second;
		}
	}

	if (closestDate.empty()) {
		return -1;
	}
	return closestPrice;
}

bool isSpace(unsigned char c) {
	return std::isspace(c);
}

bool BitcoinExchange::isValidDate(std::string &date) {
	date.erase(std::remove_if(date.begin(), date.end(), isSpace), date.end());
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
	for (std::string::size_type i = 0; i < date.size(); ++i) {
		if (i == 4 || i == 7) continue;
		if (!isdigit(date[i])) return false;
	}
	int year, month, day;
	std::stringstream ssYear(date.substr(0, 4));
	std::stringstream ssMonth(date.substr(5, 2));
	std::stringstream ssDay(date.substr(8, 2));

	ssYear >> year;
	ssMonth >> month;
	ssDay >> day;
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31) return false;
	return true;
}
