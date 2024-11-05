/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:41:21 by rwintgen          #+#    #+#             */
/*   Updated: 2024/11/05 13:42:32 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_TPP
# define BITCOINEXCHANGE_TPP

# include "BitcoinExchange.hpp"

template <typename T>
T fromString(const std::string &str)
{
	std::stringstream	ss(str);
	T					result;

	ss >> result;

	if (ss.fail() || !ss.eof())
	{
		throw std::runtime_error("Invalid conversion: " + str);
	}

	return (result);
}

#endif