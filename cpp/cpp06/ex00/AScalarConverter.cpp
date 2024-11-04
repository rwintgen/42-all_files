/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScalarConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:22:34 by romain            #+#    #+#             */
/*   Updated: 2024/11/03 12:01:05 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AScalarConverter.hpp"

AScalarConverter::AScalarConverter(void)
{
}

AScalarConverter::AScalarConverter(AScalarConverter const &src)
{
	(void) src;
}

AScalarConverter::~AScalarConverter(void)
{
}

void	AScalarConverter::convert(std::string const &str)
{
	if (!str.empty())
	{
		toChar(str);
		toInt(str);
		toFloat(str);
		toDouble(str);
	}
}

void	toChar(std::string const &str)
{
	if (!(str == "nan" || str == "nanf" || str == "+inf" \
		|| str == "+inff" || str == "-inf" || str == "-inff"))
	{
		char*	str_end;
		int		c = strtol(str.c_str(), &str_end, BASE);

		if (*str_end == '\0' || (*str_end == '.' && str.length() != 1))
		{
			if (c >= 32 && c <= 126)
				std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
			else
				std::cout << "char: non displayable" << std::endl;
			return ;
		}
	}
	std::cout << "char: impossible" << std::endl;
}

void	toInt(std::string const &str)
{
	if (!(str == "nan" || str == "nanf" || str == "+inf" \
		|| str == "+inff" || str == "-inf" || str == "-inff"))
	{
		char	*str_end;
		int		i = std::strtol(str.c_str(), &str_end, BASE);

		if (*str_end == '\0' || (*str_end == '.' && str.length() != 1))
		{
			std::cout << "int: " << i << std::endl;
			return ;
		}
	}
	std::cout << "int: impossible" << std::endl;
}

void	toFloat(std::string const &str)
{
	if ((str == "nan" || str == "nanf" || str == "+inf" \
		|| str == "+inff" || str == "-inf" || str == "-inff"))
	{
		std::cout << "float: " << str << "f" << std::endl;
		return ;
	}

	char*	str_end;
	float	f = std::strtof(str.c_str(), &str_end);

	if (*str_end == '\0' || std::isdigit(*(str_end - 1)))
	{
		std::cout << "float: ";
		printDecimals(f, FLOAT);
		std::cout << "f" << std::endl;
		return ;
	}
	std::cout << "float: impossible" << std::endl;
}

void	toDouble(std::string const &str)
{
	if ((str == "nan" || str == "nanf" || str == "+inf" \
		|| str == "+inff" || str == "-inf" || str == "-inff"))
	{
		std::cout << "double: " << str << std::endl;
		return ;
	}

	char*	str_end;
	double	d = std::strtod(str.c_str(), &str_end);

	if (*str_end == '\0' || std::isdigit(*(str_end - 1)))
	{
		std::cout << "double: ";
		printDecimals(d, DOUBLE);
		std::cout << std::endl;
		return ;
	}
	std::cout << "double: impossible" << std::endl;
}