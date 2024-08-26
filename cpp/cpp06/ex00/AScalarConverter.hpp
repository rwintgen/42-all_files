/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScalarConverter.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:22:32 by romain            #+#    #+#             */
/*   Updated: 2024/08/26 12:32:35 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASCALARCONVERTER_HPP
# define ASCALARCONVERTER_HPP

# include <iostream>
# include <string>

# define BASE 10
# define FLOAT 0
# define DOUBLE 1
# define POWER 6

class AScalarConverter
{
	private:
		AScalarConverter();
		AScalarConverter(AScalarConverter const &src);
		~AScalarConverter();
		
		virtual AScalarConverter &operator=(AScalarConverter const &src) const = 0;

	public:
		static void convert(std::string const &str);
};

template <typename T>
void	printDecimals(T value, unsigned int type)
{
    T	number = type ? static_cast<double>(value) : static_cast<float>(value);
    int	integer = static_cast<int>(number);
    int	decimals = static_cast<int>((number - integer) * std::pow(10, POWER) + 0.5);
    std::cout << integer << "." << decimals;
}

void toChar(std::string const &str) /* __attribute__((unused)) */;
void toInt(std::string const &str) /* __attribute__((unused)) */;
void toFloat(std::string const &str) /* __attribute__((unused)) */;
void toDouble(std::string const &str) /* __attribute__((unused)) */;

#endif