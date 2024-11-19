/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:56:11 by romain            #+#    #+#             */
/*   Updated: 2024/11/19 13:37:05 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream	file("./data.csv");

	if (!file.is_open())
		throw std::runtime_error("Cannot open file: data.csv");

	std::string	line;
	bool		isHeader = true;

	while (std::getline(file, line))
	{
		trimWhitespaces(line);

		if (isHeader)
		{
			isHeader = false;
			if (line != "date,exchange_rate")
				throw std::runtime_error("Invalid file header: " + line);
			continue ;
		}

		std::istringstream	iss(line);
		std::string			date;
		std::string			exchangeRate;

		if (!std::getline(iss, date, ',') || \
			!std::getline(iss, exchangeRate, ','))
			throw std::runtime_error("Invalid line: " + line);

		if (date.empty() || exchangeRate.empty())
			throw std::runtime_error("Empty field in line: " + line);

		trimWhitespaces(date);
		trimWhitespaces(exchangeRate);

		if (!isValidDate(date))
			throw std::runtime_error("Invalid date: " + date);

		try
		{
			this->_data[date] = fromString<double>(exchangeRate);
		}
		catch (std::exception &e)
		{
			throw std::runtime_error("Invalid exchange rate: " + exchangeRate);
		}
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
		this->_data = src._data;
	return (*this);
}

void	BitcoinExchange::readFile(const std::string &filename)
{
	std::ifstream	file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Cannot open file: " + filename);

	std::string	line;
	bool		isHeader = true;

	while (std::getline(file, line))
	{
		trimWhitespaces(line);

		if (line.empty())
			continue ;

		try
		{
			std::istringstream	iss(line);
			std::string			date;
			std::string			value;

			if (!std::getline(iss, date, '|') || \
				!std::getline(iss, value, '|'))
				throw std::runtime_error("Invalid line format");

			if (date.empty() || value.empty())
				throw std::runtime_error("Empty field in line");

			trimWhitespaces(date);
			trimWhitespaces(value);

			if (isHeader)
			{
				isHeader = false;
				if (date != "date" || value != "value")
					throw std::runtime_error("Invalid file header");
				printHeader();
				continue ;
			}

			if (!isValidDate(date) || !isValidAmount(value))
				throw std::runtime_error("Invalid date or value");

			printLine(date, value);
		}
		catch (std::exception const &e)
		{
			std::cerr << "Error on line: \"" << line << "\" - " << e.what() << std::endl;
		}
	}
}

void	BitcoinExchange::trimWhitespaces(std::string &str)
{
	str.erase(0, str.find_first_not_of(WHITESPACES));
	str.erase(str.find_last_not_of(WHITESPACES) + 1);
}

bool	BitcoinExchange::isValidDate(std::string const &date)
{
	regex_t	regex;

	if (regcomp(&regex, "^[0-9]{4}-[0-9]{2}-[0-9]{2}$", REG_EXTENDED))
		return (false);

	if (regexec(&regex, date.c_str(), 0, NULL, 0) != 0)
	{
		regfree(&regex);
		return (false);
	}

    regfree(&regex);

	int	year = fromString<int>(date.substr(0, 4));
	int	month = fromString<int>(date.substr(5, 2));
	int	day = fromString<int>(date.substr(8, 2));

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

bool	BitcoinExchange::isValidAmount(std::string const &amount)
{
	regex_t	regex;

	if (regcomp(&regex, "^\\d+(\\.\\d+)?$", REG_EXTENDED))
	{
		regfree(&regex);
		return (false);
	}
	
	try
	{
		double	value = fromString<double>(amount);

		if (value < 0 || value > 1000)
		{
			regfree(&regex);
			return (false);
		}
	}
	catch (std::exception &e)
	{
		regfree(&regex);
		return (false);
	}

	regfree(&regex);
	return (true);
}

void	BitcoinExchange::printHeader(void)
{
	std::cout << std::left << std::setw(15) << "date"
			  << std::setw(10) << "qty"
			  << std::setw(10) << "price"
			  << "result" << std::endl;
}

void	BitcoinExchange::printLine(const std::string &date, const std::string &value)
{
	double	amount;

	try 
	{
		amount = fromString<double>(value);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Invalid value: " << value << std::endl;
		return ;
	}

	std::map<std::string, double>::iterator it = _data.lower_bound(date);

	if (it == _data.end() || it->first != date)
	{
		if (it == _data.begin())
		{
			std::cerr << "No valid date found for: " << date << std::endl;
			return ;
		}
		it--;
	}

	double	exchangeRate = it->second;
	double	result = amount * exchangeRate;

	std::cout << std::left << std::setw(15) << date
			  << std::setw(10) << value
			  << std::setw(10) << exchangeRate
			  << std::fixed << std::setprecision(2) << result << std::endl;
}
