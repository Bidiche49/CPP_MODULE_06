/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:59:37 by ntardy            #+#    #+#             */
/*   Updated: 2024/03/21 23:12:55 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data		*structPtr = new Data;
	uintptr_t	uPtr = 0;
	Data		*deserialized;

	std::cout << "Value uPtr before serialize : " << std::endl;
	std::cout << uPtr << std::endl;

	structPtr->nb = 42;
	uPtr = Serializer().serialize(structPtr);
	deserialized = Serializer().deserialize(uPtr);

	std::cout << "\nValue nb in struct : " << std::endl;
	std::cout << structPtr->nb << std::endl;
	std::cout << "\nValue uPtr after serialize : " << std::endl;
	std::cout << uPtr << std::endl;
	std::cout << "\nValue nb after deserialize : " << std::endl;
	std::cout << deserialized->nb << std::endl;
	std::cout << "\nDiff between structPtr and deserialized ? ";
	std::cout << (deserialized == structPtr ? "OK, no diff." : "KO diff.") << std::endl;

	delete structPtr;

	return (0);
}
