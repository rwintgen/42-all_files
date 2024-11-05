/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:56:19 by romain            #+#    #+#             */
/*   Updated: 2024/11/05 13:42:55 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include <regex.h>

# define WHITESPACES " \t\n\r\f\v"

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(BitcoinExchange const &src);

		void	readFile(std::string const &filename);

	private:
		std::map<std::string, double>	_data;

		void	printHeader(void);
		void	printLine(const std::string &date, const std::string &value);
		void	trimWhitespaces(std::string &str);
		bool	isValidDate(std::string const &date);
		bool	isValidAmount(std::string const &amount);
};

#include "BitcoinExchange.tpp"

#endif