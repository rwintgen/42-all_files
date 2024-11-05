/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:38:51 by romain            #+#    #+#             */
/*   Updated: 2024/11/05 12:35:48 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl;
		return (1);
	}

	std::string	strInput;
	
	for (int i = 1; i < argc; i++)
	{
		strInput += argv[i];
		if (i < argc - 1)
			strInput += " ";
	}

	try
	{
		PmergeMe	pm(strInput);

		pm.printVector(void);
		pm.printDeque(void);
		
		pm.sortVector(void);
		pm.sortDeque(void);

		pm.printVector(void);
		pm.printDeque(void);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}