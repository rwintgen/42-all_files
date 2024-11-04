/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScalarConverter.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:22:32 by romain            #+#    #+#             */
/*   Updated: 2024/11/03 11:58:16 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASCALARCONVERTER_HPP
# define ASCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>

# define BASE 10
# define FLOAT 0
# define DOUBLE 1

class AScalarConverter
{
	private:
		AScalarConverter(void);
		AScalarConverter(AScalarConverter const &src);
		~AScalarConverter(void);
		
		virtual AScalarConverter &operator=(AScalarConverter const &src) const = 0;

	public:
		static void convert(std::string const &str);
};

template <typename T>
void printDecimals(T value, unsigned int type);

void toChar(std::string const &str) /* __attribute__((unused)) */;
void toInt(std::string const &str) /* __attribute__((unused)) */;
void toFloat(std::string const &str) /* __attribute__((unused)) */;
void toDouble(std::string const &str) /* __attribute__((unused)) */;

# include "AScalarConverter.tpp"

#endif