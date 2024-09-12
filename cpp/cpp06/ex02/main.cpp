/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:25:16 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:30:00 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int	main(void)
{
	srand(static_cast<unsigned int>(time(0)));

	Base	*obj = generate(void);

	identifyPtr(obj);
	identifyRef(*obj);
	delete obj;

	return (0);
}
