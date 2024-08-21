/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:57:12 by romain            #+#    #+#             */
/*   Updated: 2024/08/21 12:16:46 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat				arnold("Arnold", 3);
		ShrubberyCreationForm	scf("DeathNote");
		RobotomyRequestForm		rrf("A public service agent");
		PresidentialPardonForm	ppf("A CROUS machine hacker");
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

			std::cout << std::endl << "==== RobotomyRequestForm ====" << std::endl;
			std::cout << rrf << std::endl;
			arnold.signForm(rrf);
			std::cout << rrf << std::endl;
			arnold.executeForm(rrf);

			std::cout << std::endl << "== PresidentialPardonForm ===" << std::endl;
			std::cout << ppf << std::endl;
			arnold.signForm(ppf);
			std::cout << ppf << std::endl;
			arnold.executeForm(ppf);

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