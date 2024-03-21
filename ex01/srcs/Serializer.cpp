/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:58:52 by ntardy            #+#    #+#             */
/*   Updated: 2024/03/21 23:00:44 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {

}

Serializer::Serializer(Serializer const & src) {
	if (this != &src)
		*this = src;
}

Serializer::~Serializer() {

}

Serializer &Serializer::operator=(Serializer const & src) {
	(void)src;
	return (*this);
}

uintptr_t Serializer::serialize(Data  *dataPtr) {
	return reinterpret_cast<uintptr_t>(dataPtr);
}

Data *Serializer::deserialize(uintptr_t uPtr) {
	return  reinterpret_cast<Data *>(uPtr);
}
