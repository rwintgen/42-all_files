/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:41:01 by romain            #+#    #+#             */
/*   Updated: 2024/08/13 12:35:43 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* randomAnimal = new Animal();
	const Animal* doggo = new Dog();
	const Animal* pussy = new Cat();
	
	std::cout << randomAnimal->getType() << std::endl;
	std::cout << doggo->getType() << std::endl;
	std::cout << pussy->getType() << std::endl;
	
	randomAnimal->makeSound();
	doggo->makeSound();
	pussy->makeSound();
	
	return (0);
}
