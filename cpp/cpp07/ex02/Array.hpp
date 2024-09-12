/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:21:08 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:32:42 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
    public:
        Array(void);
        Array(unsigned int n);
        Array(Array const &src);
        ~Array(void);

        Array	&operator=(Array const &src);
        T		&operator[](unsigned int i);

        unsigned int	size(void) const;

    private:
        T				*_array;
        unsigned int	_size;
};

#include "Array.tpp"

#endif