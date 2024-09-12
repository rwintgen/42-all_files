/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:41:12 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:36:09 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>(void)
{
	std::cout << "Default contructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src)
{
	std::cout << "Copy contructor called" << std::endl;
    *this = src;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << "Destructor called" << std::endl;
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack const &src)
{
    if (this != &src)
        std::stack<T>::operator=(src);
    return (*this);
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin(void)
{
    return (std::stack<T>::c.begin(void));
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end(void)
{
    return (std::stack<T>::c.end(void));
}

#endif