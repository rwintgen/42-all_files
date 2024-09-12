/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:59:20 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:37:51 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        try
        {
            BitcoinExchange exchange;
            exchange.readFile(argv[1]);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
    }
	else
	{
		std::cerr << "Usage: " << argv[0] << " [filename]" << std::endl;
		return (1);	
	}
	return (0);
}
