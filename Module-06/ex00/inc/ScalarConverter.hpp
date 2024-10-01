#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cerrno>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

		static bool isChar(const std::string& literal);
		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);
		static bool isPseudoLiteral(const std::string& literal);

		static void printAsChar(double value);
		static void printAsInt(double value);
		static void printAsFloat(double value);
		static void printAsDouble(double value);

	public:
		static void convert(const std::string& literal);
};

#endif
