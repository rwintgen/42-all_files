/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:56:19 by romain            #+#    #+#             */
/*   Updated: 2024/08/29 14:32:03 by romain           ###   ########.fr       */
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

	private:
		std::map<std::string, double>	_data;

		void	trimWhitespaces(std::string &str);
		bool	isValidDate(std::string const &date);
		void	readFile(std::string const &filename);
		
};

#endif