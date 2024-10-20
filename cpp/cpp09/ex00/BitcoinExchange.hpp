/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:56:19 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:37:51 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <regex>
# include <map>
# include <fstream>
# include <sstream>

# define WHITESPACES " \t\n\r\f\v"
# define OUTPUT_HEADER "date\t\t|\tqty\t|\tprice\t->\tresult"

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

		void	trimWhitespaces(std::string &str);
		bool	isValidDate(std::string const &date);
		bool	isValidAmount(std::string const &amount);
		void	printLine(std::map<std::string, double> &data, std::string const &date, std::string const &value);		
};

#endif