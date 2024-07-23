/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:46:53 by romain            #+#    #+#             */
/*   Updated: 2024/07/23 21:58:08 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "string's address: " << &string << std::endl;
	std::cout << "stringPTR's held memory address: " << stringPTR << std::endl;
	std::cout << "stringREF's held memory address: " << &stringREF << std::endl;

	std::cout << "string's value: " << string << std::endl;
	std::cout << "stringPTR's pointed value: " << *stringPTR << std::endl;
	std::cout << "stringREF's pointed value: " << stringREF << std::endl;
	
	return (0);
}
