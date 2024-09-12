/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASerializer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:29:43 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:29:30 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASERIALIZER_HPP
# define ASERIALIZER_HPP

# include <iostream>
# include <stdint.h>

class	Data
{
	public:
		int	content;
};

class	ASerializer
{
	private:
		ASerializer(void);
		ASerializer(ASerializer const &src);
		~ASerializer(void);

		virtual ASerializer	&operator=(ASerializer const &src) = 0;

	public:
		static uintptr_t	serialize(Data *data);
		static Data*		deserialize(uintptr_t raw);
};

#endif