/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:56:19 by romain            #+#    #+#             */
/*   Updated: 2024/08/30 16:50:01 by romain           ###   ########.fr       */
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

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();

		BitcoinExchange	&operator=(BitcoinExchange const &src);

		void	readFile(std::string const &filename);

	private:
		std::map<std::string, double>	_data;

		void	trimWhitespaces(std::string &str);
		bool	isValidDate(std::string const &date);
		// bool	isValidAmount(std::string const &amount);
		void	printData();
		
};

#endif