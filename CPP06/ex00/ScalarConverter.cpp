
#include "ScalarConverter.hpp"

static bool isValidChar(const std::string &input)
{
	if (input.length() != 1)
		return false;
	unsigned char c = static_cast<unsigned char>(input[0]);
	if (std::isdigit(c))
		return false;
	return true;
}

static bool isValidInt(const std::string &input)
{
	if (input.empty())
		return false;
	unsigned int i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.length())
		return false;
	while (i < input.length())
	{
		if (!isdigit(input[i]))
			return false;
		i++;
	}
	return true;
}

static bool isDot(const std::string &input)
{
	if (input.empty())
		return false;
	unsigned int i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.length())
		return false;
	bool bef_digit = false;
	bool af_digit = false;
	while (i < input.length() && isdigit(input[i]))
	{
		bef_digit = true;
		i++;
	}
	if (i < input.length() && input[i] == '.')
	{
		i++;
		for (; i < input.length() && isdigit(input[i]); i++)
			af_digit = true;
	}
	if (i != input.length())
		return false;
	if (bef_digit == false && af_digit == false)
		return false;
	return true;
}

static bool isValidFloat(const std::string &input)
{
	if (input.empty())
		return false;
	if (input[input.length() - 1] != 'f')
		return false;
	std::string core = input.substr(0, input.length() - 1);
	if (!isDot(core))
		return false;
	return true;
}

static bool isValidDouble(const std::string &input)
{
	if (input.empty())
		return false;
	if (input.find('f') != std::string::npos)
		return false;
	if (input.find('.') == std::string::npos)
		return false;
	return isDot(input);
}

static bool isSpecialFloat(const std::string &s)
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return true;
	return false;
}

static bool isSpecialDouble(const std::string &s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
		return true;
	return false;
}

static LiteralType detectType(const std::string &input)
{
	if (isSpecialFloat(input))
		return TYPE_SP_FLOAT;
	else if (isSpecialDouble(input))
		return TYPE_SP_DB;
	else if (isValidChar(input))
		return TYPE_CHAR;
	else if (isValidFloat(input))
		return TYPE_FLOAT;
	else if (isValidDouble(input))
		return TYPE_DOUBLE;
	else if (isValidInt(input))
		return TYPE_INT;
	return TYPE_INVALID;
}

static std::pair<bool, long long> parseInt(const std::string &input)
{
	long long tmp;
	std::istringstream iss(input);
	iss >> tmp;
	if (iss.fail())
		return std::make_pair(false, 0);
	return std::make_pair(true, tmp);
}

static std::pair<bool, double> parseDouble(const std::string &input)
{
	std::string str_d = input;
	char *end = 0;
	errno = 0;
	double tmp = std::strtod(str_d.c_str(), &end);
	if (end == str_d.c_str() || *end != '\0')
		return std::make_pair(false, 0.0);
	if (errno == ERANGE)
		return std::make_pair(false, 0.0);
	return std::make_pair(true, static_cast<double>(tmp));
}

static std::pair<bool, double> parseFloat(const std::string &input)
{
	std::string core = input.substr(0, input.length() - 1);
	if (!parseDouble(core).first)
		return std::make_pair(false, 0.0);
	std::pair<bool, double> tmp = parseDouble(core);
	if (!tmp.first)
		return std::make_pair(false, 0.0);
	return std::make_pair(true, tmp.second);
}

static void printFloatLiteral(float value)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << value << 'f' << std::endl;
}

static void printDoubleLiteral(double value)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

static void displaySpecials(LiteralType type, const std::string input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (type == TYPE_SP_FLOAT)
	{
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
	}
	else
	{
		std::cout << "float: " << input << 'f' << std::endl;
		std::cout << "double: " << input << std::endl;
	}
}

static void displayChar(const std::string input)
{
	unsigned char c = input[0];
	if (std::isprint(c))
		std::cout << "char: " << "'" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	int i = static_cast<int>(c);
	std::cout << "int: " << i << std::endl;
	float f = static_cast<float>(c);
	printFloatLiteral(f);
	double d = static_cast<double>(c);
	printDoubleLiteral(d);
}

static void handlePrintChar(long long input)
{
	if (input < CHAR_MIN || input > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(input);
		if (std::isprint(c))
			std::cout << "char: " << "'" << c << "'" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
	}
}

static void displayInt(long long input)
{
	handlePrintChar(input);
	if (input < INT_MIN || input > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(input) << std::endl;
	float f = static_cast<float>(input);
	printFloatLiteral(f);
	double d = static_cast<double>(input);
	printDoubleLiteral(d);
}

static void displayFloat(double input)
{
	if (input < static_cast<double>(INT_MIN) || input > static_cast<double>(INT_MAX))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		int n = static_cast<int>(input);
		handlePrintChar(n);
		std::cout << "int: " << n << std::endl;
	}
	if (input < -std::numeric_limits<float>::max() || input > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		printFloatLiteral(static_cast<float>(input));
	printDoubleLiteral(input);
}

static void displayDouble(double input)
{
	if (input < static_cast<double>(INT_MIN) || input > static_cast<double>(INT_MAX))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		int n = static_cast<int>(input);
		handlePrintChar(n);
		std::cout << "int: " << n << std::endl;
	}
	if (input < -std::numeric_limits<float>::max() || input > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		printFloatLiteral(static_cast<float>(input));
	printDoubleLiteral(input);
}

void ScalarConverter::convert(const std::string &literal)
{
	LiteralType type = detectType(literal);
	if (type == TYPE_INVALID)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	else if (type == TYPE_SP_FLOAT || type == TYPE_SP_DB)
	{
		displaySpecials(type, literal);
	}
	else if (type == TYPE_CHAR)
	{
		displayChar(literal);
		return;
	}
	else if (type == TYPE_INT)
	{
		std::pair<bool, long long> i = parseInt(literal);
		if (i.first == false)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
		displayInt(i.second);
		return;
	}
	else if (type == TYPE_FLOAT)
	{
		std::pair<bool, double> f = parseFloat(literal);
		if (f.first == false)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
		displayFloat(f.second);
		return;
	}
	else if (type == TYPE_DOUBLE)
	{
		std::pair<bool, double> d = parseDouble(literal);
		if (d.first == false)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
		displayDouble(d.second);
		return;
	}
}
