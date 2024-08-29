/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:56:11 by romain            #+#    #+#             */
/*   Updated: 2024/08/29 14:32:36 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// rm whitespaces
// file header is "date,exchange_rate"
	// if invalid header, throw std::runtime_error("Invalid file header");
// file will contains lines formatted "2009-01-02,0"
	// if invalid line
		// throw std::runtime_error("Invalid file line");
	// else
		// split line into <date>, <exchange_rate>
		// rm whitespaces
		// check if <date> is valid
			// if not, throw std::runtime_error("Invalid date");
		// store data into map: this->_data

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	file("./data.csv");

	if (!file.is_open())
	{
		throw std::runtime_error("Cannot open file");
		return ;
	}

	std::string	line;
	bool		isHeader = true;

	while (std::getline(file, line))
	{
		trimWhitespaces(line);
		if (isHeader)
		{
			isHeader = false;
			if (line != "date,exchange_rate")
				throw std::runtime_error("Invalid file header");
			continue ;
		}

		std::istringstream	inputStringStream(line);
		std::string			date;
		std::string			exchangeRate;

		std::getline(inputStringStream, date, ',');
		std::getline(inputStringStream, exchangeRate, ',');
		if (date.empty() || exchangeRate.empty())
			throw std::runtime_error("Invalid file line");
		trimWhitespaces(date);
		trimWhitespaces(exchangeRate);
		if (!isValidDate(date))
			throw std::runtime_error("Invalid date");
		try
		{
			this->_data[date] = std::stod(exchangeRate);
		}
		catch (std::exception &e)
		{
			throw std::runtime_error("Invalid exchange rate");
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
		this->_data = src._data;
	return (*this);
}

void	BitcoinExchange::trimWhitespaces(std::string &str)
{
	str.erase(0, str.find_first_not_of(WHITESPACES));
	str.erase(str.find_last_not_of(WHITESPACES) + 1);
}

bool	BitcoinExchange::isValidDate(std::string const &date)
{
	std::regex	regex("^[0-9]{4}-[0-9]{2}-[0-9]{2}$");

	if (!std::regex_match(date, regex) == true)
		return (false);
	
	int	year = std::stoi(date.substr(0, 4));
	int	month = std::stoi(date.substr(5, 2));
	int	day = std::stoi(date.substr(8, 2));
	
	if (year < 2009 || year > 2022)
		return (false);
	if (month < 1 || month > 12)
		return (false);

	switch (month)
	{
	case 4: case 6: case 9: case 11:
		if (day < 1 || day > 30)
			return (false);
		break ;
	case 2:
		{
			bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
			if (day < 1 || day > 29 || (day == 29 && !isLeapYear))
				return (false);
		}
		break ;
	default:
		if (day < 1 || day > 31)
			return (false);
	}
	return (true);
}
