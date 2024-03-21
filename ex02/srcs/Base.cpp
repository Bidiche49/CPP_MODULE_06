/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:32:09 by ntardy            #+#    #+#             */
/*   Updated: 2024/03/21 23:56:44 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

Base *generate(void){
	int random;

	srand(time(NULL));
	random = rand() % 3;

	if (!random) {
		std::cout << "New A" << std::endl;
		return (new A());
	}
	else if (random == 2) {
		std::cout << "New B" << std::endl;
		return (new B());
	}
	else {
		std::cout << "New C" << std::endl;
		return (new C());
	}
	return (NULL);
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "The real type is A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The real type is B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The real type is C." << std::endl;
}

void identify(Base &p) {
	try {
		p = dynamic_cast<A &>(p);
		std::cout << "The real type is A." << std::endl;
	}
	catch (const std::exception &e) {}

	try {
		p = dynamic_cast<B &>(p);
		std::cout << "The real type is B." << std::endl;
	}
	catch (const std::exception &e) {}

	try {
		p = dynamic_cast<C &>(p);
		std::cout << "The real type is C." << std::endl;
	}
	catch (const std::exception &e) {}
}

int main(void)
{
	Base *newBase = generate();
	identify(newBase);
	identify(*newBase);
	delete newBase;
	return 0;
}
