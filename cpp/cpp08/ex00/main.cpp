/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:49:19 by romain            #+#    #+#             */
/*   Updated: 2024/08/28 10:01:52 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Easyfind.hpp"

int	main(void)
{
	std::list<int>	lst;

	lst.push_back(0);
	lst.push_back(42);
	
	std::cout << "trying to find 42 in lst: ";
	try
	{
		std::cout << easyfind(lst, 42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "trying to find 0 in lst: ";
	try
	{
		std::cout << easyfind(lst, 0) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "trying to find 99999 in lst: ";
	try
	{
		std::cout << easyfind(lst, 99999) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
