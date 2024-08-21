/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:57:12 by romain            #+#    #+#             */
/*   Updated: 2024/08/21 10:37:59 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat				arnold("Arnold", 3);
		ShrubberyCreationForm	scf("creation_form");
		try
		{
			std::cout << std::endl << "========= Bureaucrat ========" << std::endl;
			std::cout << arnold << std::endl;
			arnold.incrementGrade();
			std::cout << arnold << std::endl;
			arnold.decrementGrade();
			std::cout << arnold << std::endl;
			std::cout << std::endl << "=== ShrubberyCreationForm ===" << std::endl;
			std::cout << scf << std::endl;
            arnold.signForm(scf);
            std::cout << scf << std::endl;
            arnold.executeForm(scf);
            std::cout << std::endl;
			return (0);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			return (1);
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}