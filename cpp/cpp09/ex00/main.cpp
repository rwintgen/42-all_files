/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:59:20 by romain            #+#    #+#             */
/*   Updated: 2024/08/29 14:34:13 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange exchange;

		exchange.readFile(argv[1]);
	}
	else
	{
		std::cerr << "Usage: " << argv[0] << " [filename]" << std::endl;
		return (1);	
	}
	return (0);
}
