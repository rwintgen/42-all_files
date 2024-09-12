/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:41:01 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:16:04 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

int main(void)
{
	const Animal* randomAnimal = new Animal(void);
	const Animal* doggo = new Dog(void);
	const Animal* pussy = new Cat(void);
	const WrongAnimal* wrongCat = new WrongAnimal(void);
	
	std::cout << std::endl;
	std::cout << randomAnimal->getType(void) << std::endl;
	std::cout << doggo->getType(void) << std::endl;
	std::cout << pussy->getType(void) << std::endl;
	std::cout << wrongCat->getType(void) << std::endl;
	
	std::cout << std::endl;
	randomAnimal->makeSound(void);
	doggo->makeSound(void);
	pussy->makeSound(void);
	wrongCat->makeSound(void);
	
	std::cout << std::endl;
	delete randomAnimal;
	delete doggo;
	delete pussy;
	delete wrongCat;

	std::cout << std::endl;
	Animal	*animals[100];
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog(void);
		else
			animals[i] = new Cat(void);
	}
	for (int i = 0; i < 100; i++)
		delete animals[i];

	std::cout << std::endl;
	
	return (0);
}
