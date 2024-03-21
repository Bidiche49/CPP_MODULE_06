/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:17:40 by ntardy            #+#    #+#             */
/*   Updated: 2024/03/21 21:58:51 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <iomanip>
#include <limits>
#include <cstdlib>

ScalarConverter::ScalarConverter()  {

}

ScalarConverter::ScalarConverter(ScalarConverter const & src)  {
	if (this != &src)
		*this = src;
}

ScalarConverter::~ScalarConverter() {

}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const & src)    {
	(void)src;
	return (*this);
}

std::string wichLit(std::string entry) {
	if (entry == "-inf" || entry == "-inff") {
		return std::string("-inf");
	} else if (entry == "+inf" || entry == "+inff") {
		return std::string("+inf");
	} else if (entry == "nan" || entry == "nanf") {
		return std::string("nan");
	} else {
		return "";
	}
}

void ScalarConverter::convert(const std::string& entry) {

	std::string literal = wichLit(entry);
	long int intRes = 0;
	float floatRes = 0.0f;
	double doubleRes = 0.0;

	int nbComas = 0;
	for (size_t i = 0; i < entry.size(); ++i) {
		if (!literal.empty())
			break;
		if (!isdigit(entry[i]) && entry[0] != '-' && entry[0] != '+' && entry[i] != '.' && entry[i] != 'f') {
			std::cout << "Wrong entry" << std::endl;
			return;
		}
		if (entry[i] == '.' &&(++nbComas > 1 || i == 0 || i >= entry.size() - 1)) {
				std::cout << "Wrong entry" << std::endl;
				return;
		}
		if (entry[i] == 'f' && (i < 3 || !isdigit(entry[i-1]) || nbComas == 0 || i != entry.size() -1)) {
				std::cout << "Wrong entry" << std::endl;
				return;
		}
	}

	if (!literal.empty()) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return ;
	}

	intRes = static_cast<long>(atol(entry.c_str()));

	if (intRes < 0 || intRes > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!(isprint(intRes))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(intRes) << "'" << std::endl;
	}

	if (intRes >= std::numeric_limits<int>::min() && intRes <= std::numeric_limits<int>::max()) {
		std::cout << "int: " << intRes << std::endl;
	}
	else {
		std::cout << "int: overflow" << std::endl;
	}

	floatRes = std::atof(entry.c_str());
	doubleRes = static_cast<double>(floatRes);

	std::cout << "float: " << floatRes;
	if (!(floatRes - static_cast<int>(floatRes)))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << doubleRes;
	if (!(doubleRes - static_cast<int>(doubleRes)))
		std::cout << ".0";
	std::cout << std::endl;
}
