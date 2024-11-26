/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:09:18 by romain            #+#    #+#             */
/*   Updated: 2024/11/26 12:54:54 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <string>

class	RPN
{
	public:
		RPN(std::string const &expression);
		RPN(RPN const &src);
		~RPN(void);

		RPN	&operator=(RPN const &src);

		static bool	isValidInput(std::string const &input);
		void		printResult(void) const;
		
	private:
		std::stack<int>	_stack;
		bool			_error;
};

#endif