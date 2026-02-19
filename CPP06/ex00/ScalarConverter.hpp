
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <cerrno>
#include <cctype>
#include <limits>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <utility>

enum LiteralType
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_SP_FLOAT,
	TYPE_SP_DB,
	TYPE_INVALID
};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

public:
	static void convert(const std::string &literal);
};

#endif