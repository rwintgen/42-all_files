/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:41:01 by romain            #+#    #+#             */
/*   Updated: 2024/09/26 13:53:12 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* randomAnimal = new Animal();
	const Animal* doggo = new Dog();
	const Animal* pussy = new Cat();
	const WrongAnimal* wrongPussy = new WrongCat();
	
	std::cout << std::endl;
	std::cout << randomAnimal->getType() << std::endl;
	std::cout << doggo->getType() << std::endl;
	std::cout << pussy->getType() << std::endl;
	std::cout << wrongPussy->getType() << std::endl;
	
	std::cout << std::endl;
	randomAnimal->makeSound();
	doggo->makeSound();
	pussy->makeSound();
	wrongPussy->makeSound();
	
	std::cout << std::endl;
	delete randomAnimal;
	delete doggo;
	delete pussy;
	delete wrongPussy;
	
	std::cout << std::endl;
	
	return (0);
}
