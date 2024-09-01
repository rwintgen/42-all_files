/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:09:11 by romain            #+#    #+#             */
/*   Updated: 2024/09/01 15:46:55 by romain           ###   ########.fr       */
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
