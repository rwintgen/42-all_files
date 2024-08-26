/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:25:35 by romain            #+#    #+#             */
/*   Updated: 2024/08/26 16:02:01 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <cstdlib>

class	Base
{
	public:
		virtual ~Base() {};
};

class	A : public Base
{
	public:
		A() {};
		virtual ~A() {};
};

class	B : public Base
{
	public:
		B() {};
		virtual ~B() {};
};

class	C : public Base
{
	public:
		C() {};
		virtual ~C() {};
};

Base	*generate(void);
void	identifyPtr(Base *ptr);
void	identifyRef(Base &ref);

#endif