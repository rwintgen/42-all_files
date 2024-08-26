/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScalarConverter.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:22:32 by romain            #+#    #+#             */
/*   Updated: 2024/08/26 11:46:13 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASCALARCONVERTER_HPP
# define ASCALARCONVERTER_HPP

# include <iostream>
# include <string>

# define BASE 10

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

void toChar(std::string const &str) /* __attribute__((unused)) */;
void toInt(std::string const &str) /* __attribute__((unused)) */;
void toFloat(std::string const &str) /* __attribute__((unused)) */;
void toDouble(std::string const &str) /* __attribute__((unused)) */;

#endif