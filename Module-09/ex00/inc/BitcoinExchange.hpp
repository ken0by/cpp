#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <sys/stat.h>

class BitcoinExchange
{
	private:
		std::map<std::string, double> prices;
		void loadPrices(const std::string& filename);

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		bool isValidDate(std::string& date);
		double getPriceForDate(const std::string &date);
};

#endif
