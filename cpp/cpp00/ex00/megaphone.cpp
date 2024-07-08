/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:52:58 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/08 13:04:08 by rwintgen         ###   ########.fr       */
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

		for (int j = 0; j < (int)tmp.length(); j++)
		{
			result += std::toupper(tmp[j]);
		}
		result += ' ';
	}
	std::cout << result << std::endl;

	return (0);
}
