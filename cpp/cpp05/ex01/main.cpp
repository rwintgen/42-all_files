/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:57:12 by romain            #+#    #+#             */
/*   Updated: 2024/10/30 16:31:33 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat arnold("Arnold", 1);
		Form contract("contract", 1, 1);

		// empty name and grade too low/high:
		// Form contract("", 1, 1);
		// Form contract("contract", 1, 151);
		// Form contract("contract", 0, 1);

		std::cout << arnold << std::endl;
		std::cout << contract << std::endl;
		contract.beSigned(arnold);
		std::cout << contract << std::endl;
		arnold.signForm(contract);

		// sign contract twice
		// contract.beSigned(arnold);

		// grade too low/high for signing:
		// arnold.decrementGrade();
		// std::cout << arnold << std::endl;
		// contract.beSigned(arnold);

		return (0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}