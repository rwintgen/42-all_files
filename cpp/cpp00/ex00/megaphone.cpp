/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:52:58 by rwintgen          #+#    #+#             */
/*   Updated: 2024/09/17 11:34:04 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	std::string result = "";

	if (!argv[1])
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string tmp = argv[i];

		for (size_t j = 0; j < tmp.length(); j++)
			result += std::toupper(tmp[j]);
	}
	std::cout << result << std::endl;
	return (0);
}
