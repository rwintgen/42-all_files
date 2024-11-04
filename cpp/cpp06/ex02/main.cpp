/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:25:16 by romain            #+#    #+#             */
/*   Updated: 2024/11/03 12:10:13 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int	main(void)
{
	srand(static_cast<unsigned int>(time(0)));

	Base	*obj = generate();

	identifyPtr(obj);
	identifyRef(*obj);
	delete obj;

	return (0);
}
