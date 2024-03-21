/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:12:28 by ntardy            #+#    #+#             */
/*   Updated: 2024/03/21 14:39:47 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"


int main(int argc, char **argv) {
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
	}
	else
		std::cout << "Wrong number of arguments" << std::endl;

	return (0);
}

// int main() {
// 	ScalarConverter::convert("42");
// 	ScalarConverter::convert("-42");
// 	ScalarConverter::convert("3.14");
// 	ScalarConverter::convert("123.456");
// 	ScalarConverter::convert("A");
// 	ScalarConverter::convert("7");
// 	ScalarConverter::convert("0");
// 	ScalarConverter::convert("4.2f");
// 	ScalarConverter::convert("-4.2f");
// 	ScalarConverter::convert("+inff");
// 	ScalarConverter::convert("-inff");
// 	ScalarConverter::convert("nanf");
// 	ScalarConverter::convert("0.0");
// 	ScalarConverter::convert("-4.2");
// 	ScalarConverter::convert("+inf");
// 	ScalarConverter::convert("-inf");
// 	ScalarConverter::convert("nan");

// 	return 0;
// }
