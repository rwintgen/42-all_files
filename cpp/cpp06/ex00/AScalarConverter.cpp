/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScalarConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:22:34 by romain            #+#    #+#             */
/*   Updated: 2024/08/26 11:47:50 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AScalarConverter.hpp"

AScalarConverter::AScalarConverter()
{

}

AScalarConverter::AScalarConverter(AScalarConverter const &src)
{
	*this = src;
}

AScalarConverter::~AScalarConverter()
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
		char	*str_end;
		int		c = std::strtol(str.c_str(), &str_end, BASE);
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
