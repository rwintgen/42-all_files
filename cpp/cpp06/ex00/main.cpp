/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:14:22 by romain            #+#    #+#             */
/*   Updated: 2024/08/26 10:50:09 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <value>" << std::endl;
		return (1);
	}
	AScalarConverter::convert(argv[1]);
	return (0);
}