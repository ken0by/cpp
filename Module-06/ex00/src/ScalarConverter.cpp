#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return (*this);
}

bool ScalarConverter::isChar(const std::string& literal) {
	return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal) {
	char *end;
	std::strtol(literal.c_str(), &end, 10);
	return *end == '\0';
}

bool ScalarConverter::isFloat(const std::string& literal) {
	char *end;
	std::strtof(literal.c_str(), &end);
	return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string& literal) {
	char *end;
	std::strtod(literal.c_str(), &end);
	return *end == '\0';
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
	return literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff";
}

void ScalarConverter::printAsChar(double value) {
	if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<int>(value))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
}

void ScalarConverter::printAsInt(double value) {
	if (std::isnan(value) || std::isinf(value) || value > std::numeric_limits<int>::max()){
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

void ScalarConverter::printAsFloat(double value) {
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(value)) {
		std::cout << "float: nanf" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
	} else if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	}
}

void ScalarConverter::printAsDouble(double value) {
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(value)) {
		std::cout << "double: nan" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
	} else {
		std::cout << "double: " << value << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal) {
	double value;

	if (isPseudoLiteral(literal)) {
		if (literal == "nan" || literal == "nanf") {
			value = std::numeric_limits<double>::quiet_NaN();
		} else if (literal == "+inf" || literal == "+inff") {
			value = std::numeric_limits<double>::infinity();
		} else if (literal == "-inf" || literal == "-inff") {
			value = -std::numeric_limits<double>::infinity();
		}
		printAsChar(value);
		printAsInt(value);
		printAsFloat(value);
		printAsDouble(value);
		return;
	}

	if (isChar(literal)) {
		value = static_cast<double>(literal[0]);
	} else if (isInt(literal)) {
		value = std::strtol(literal.c_str(), NULL, 10);
	} else if (isFloat(literal)) {
		value = std::strtof(literal.c_str(), NULL);
	} else if (isDouble(literal)) {
		value = std::strtod(literal.c_str(), NULL);
	} else {
		std::cout << "Invalid input" << std::endl;
		return;
	}

	printAsChar(value);
	printAsInt(value);
	printAsFloat(value);
	printAsDouble(value);
}
