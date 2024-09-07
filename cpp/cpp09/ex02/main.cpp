/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:38:51 by romain            #+#    #+#             */
/*   Updated: 2024/09/07 12:32:00 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::string	strInput;

	for (int i = 0; i < argc; i++)
		strInput += argv[i] + std::string(" ");
	try
	{
		PmergeMe	pm(strInput); // check what kind of argument to pass here
		pm.sortNumbers();
		pm.printResult();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}