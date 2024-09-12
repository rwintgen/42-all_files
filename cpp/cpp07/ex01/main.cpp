/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:00:22 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:32:43 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"

static void	printInt(int &i)
{
	std::cout << i << " ";	
}

static void	printChar(char &c)
{
	std::cout << c << " ";	
}

int main(void) 
{
	int		tab[] = {0, 1, 2, 3, 4};
	char	tab2[] = {'a', 'b', 'c', 'd', 'e'};

	iter(tab, 5, printInt);
	std::cout << std::endl;
	iter(tab2, 5, printChar);

	return (0);
}
