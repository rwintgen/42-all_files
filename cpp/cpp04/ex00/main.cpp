/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:41:01 by romain            #+#    #+#             */
/*   Updated: 2024/10/29 15:51:55 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* randomAnimal = new Animal();
	const Animal* doggo = new Dog();
	const Animal* pussy = new Cat();
	const WrongAnimal* wrongPussy = new WrongCat();
	const WrongCat*	realWrongCat = new WrongCat();
	Dog i;
	Dog ii;

	ii = i;
	std::cout << std::endl;
	std::cout << randomAnimal->getType() << std::endl;
	std::cout << doggo->getType() << std::endl;
	std::cout << pussy->getType() << std::endl;
	std::cout << wrongPussy->getType() << std::endl;
	std::cout << realWrongCat->getType() << std::endl;
	
	std::cout << std::endl;
	randomAnimal->makeSound();
	doggo->makeSound();
	pussy->makeSound();
	wrongPussy->makeSound();
	realWrongCat->makeSound();
	
	std::cout << std::endl;
	delete randomAnimal;
	delete doggo;
	delete pussy;
	delete wrongPussy;
	delete realWrongCat;
	
	std::cout << std::endl;
	
	return (0);
}
