/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:57:12 by romain            #+#    #+#             */
/*   Updated: 2024/10/30 16:19:56 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	arnold("Arnold", 3);

		// empty name and grade too low/high:
		// Bureaucrat	arnold("", 3);
		// Bureaucrat	arnold("Arnold", 1);
		// Bureaucrat	bernard("Bernard", 0);
		// Bureaucrat	charlie("Charlie", 151);

		std::cout << arnold << std::endl;
		arnold.incrementGrade();
		std::cout << arnold << std::endl;
		arnold.decrementGrade();
		std::cout << arnold << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}