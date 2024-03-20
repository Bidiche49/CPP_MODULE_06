/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:10:00 by ntardy            #+#    #+#             */
/*   Updated: 2024/03/20 01:10:13 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>

class ScalarConverter {
public:
	// Static method to convert string representation of literals to various scalar types
	static void convert(const std::string& value) {
		// Convert to char
		try {
			char c = std::stoi(value);
			if (isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		} catch (const std::invalid_argument& e) {
			std::cout << "char: impossible" << std::endl;
		} catch (const std::out_of_range& e) {
			std::cout << "char: impossible" << std::endl;
		}

		// Convert to int
		try {
			int i = std::stoi(value);
			std::cout << "int: " << i << std::endl;
		} catch (const std::invalid_argument& e) {
			std::cout << "int: impossible" << std::endl;
		} catch (const std::out_of_range& e) {
			std::cout << "int: impossible" << std::endl;
		}

		// Convert to float
		try {
			float f = std::stof(value);
			std::cout << "float: " << f << "f" << std::endl;
		} catch (const std::invalid_argument& e) {
			std::cout << "float: impossible" << std::endl;
		} catch (const std::out_of_range& e) {
			std::cout << "float: impossible" << std::endl;
		}

		// Convert to double
		try {
			double d = std::stod(value);
			std::cout << "double: " << d << std::endl;
		} catch (const std::invalid_argument& e) {
			std::cout << "double: impossible" << std::endl;
		} catch (const std::out_of_range& e) {
			std::cout << "double: impossible" << std::endl;
		}
	}
};

#endif
