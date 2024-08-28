/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:56:11 by romain            #+#    #+#             */
/*   Updated: 2024/08/28 17:55:17 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	file("./data.csv");

	if (!file.is_open())
	{
		throw std::runtime_error("Cannot open file");
		return ;
	}
	std::string	line;
	while (std::getline(file, line))
	{
		// file header is "date,exchange_rate"
			// if invalid header, throw std::runtime_error("Invalid file header");
		// file will contains lines formatted "2009-01-02,0"
			// if invalid line
				// throw std::runtime_error("Invalid file line");
			// else
				// rm whitespaces
				// split line into <date>, <exchange_rate>
				// check if <date> is valid
					// if not, throw std::runtime_error("Invalid date");
				// store data into map: this->_data
	}
}
