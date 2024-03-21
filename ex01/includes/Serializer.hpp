/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:58:29 by ntardy            #+#    #+#             */
/*   Updated: 2024/03/21 23:11:13 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	int nb;
};

class   Serializer  {
	public:
		Serializer();
		Serializer(Serializer const & src);
		~Serializer();

		Serializer  &operator=(Serializer const & src);

		static uintptr_t serialize(Data *dataPtr);
		static Data *deserialize(uintptr_t uPtr);
};

#endif
