/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASerializer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:29:43 by romain            #+#    #+#             */
/*   Updated: 2024/08/26 15:12:06 by romain           ###   ########.fr       */
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
		ASerializer();
		ASerializer(ASerializer const &src);
		~ASerializer();

		virtual ASerializer	&operator=(ASerializer const &src) = 0;

	public:
		static uintptr_t	serialize(Data *data);
		static Data*		deserialize(uintptr_t raw);
};

#endif