/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:09:11 by romain            #+#    #+#             */
/*   Updated: 2024/11/05 15:03:09 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || RPN::isValidInput(argv[1]) == false)
	{	
		std::cerr << "Error" << std::endl;
		return (1);
	}
	RPN	rpn(argv[1]);
	rpn.printResult();
}
