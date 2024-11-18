/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:38:51 by romain            #+#    #+#             */
/*   Updated: 2024/11/15 14:38:06 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl;
		return (1);
	}

	std::string	input;
	
	for (int i = 1; i < argc; i++)
	{
		input += argv[i];
		if (i < argc - 1)
			input += " ";
	}

	try
	{
		PmergeMe	pm(input);
		
		pm.printVector(true);
		// pm.printDeque(true);

		double	timeVector = pm.sortVector();
		double	timeDeque = pm.sortDeque();

		pm.printVector(false);
		// pm.printDeque(false);

		std::cout << "Time to process a range of " << (argc - 1) 
				  << " elements with std::vector: " << timeVector << "s" << std::endl;
		std::cout << "Time to process a range of " << (argc - 1) 
				  << " elements with std::deque: " << timeDeque << "s" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}