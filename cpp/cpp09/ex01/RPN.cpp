/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:09:16 by romain            #+#    #+#             */
/*   Updated: 2024/11/26 12:57:54 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string const &expression) : _error(false)
{
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token)
	{
		if (token == "+")
		{
			int	a = _stack.top();
			_stack.pop();
			int	b = _stack.top();
			_stack.pop();
			_stack.push(b + a);
		}
		else if (token == "-")
		{
			int	a = _stack.top();
			_stack.pop();
			int	b = _stack.top();
			_stack.pop();
			_stack.push(b - a);
		}
		else if (token == "*")
		{
			int	a = _stack.top();
			_stack.pop();
			int	b = _stack.top();
			_stack.pop();
			_stack.push(b * a);
		}
		else if (token == "/")
		{
			int	a = _stack.top();
			_stack.pop();
			int	b = _stack.top();
			_stack.pop();
			if (a == 0)
			{
				std::cerr << "Error, division by zero" << std::endl;
				_error = true;
				return ;
			}
			_stack.push(b / a);
		}
		else
		{
			std::istringstream	iss(token);
			int					value;

			iss >> value;
			_stack.push(value);
		}
	}
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN::~RPN(void)
{
}

RPN	&RPN::operator=(RPN const &src)
{
	if (this != &src)
	{
		this->_stack = src._stack;
	}
	return (*this);
}

bool RPN::isValidInput(std::string const &input)
{
	std::istringstream iss(input);
	std::string token;
	int operandCount = 0;

	while (iss >> token)
	{
		if (std::isdigit(token[0]) && token.size() == 1)
			operandCount++;
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (operandCount < 2)
				return (false);
			operandCount--;
		}
		else
			return (false);
	}
	return (operandCount == 1);
}

void	RPN::printResult(void) const
{
	if (!_error)
		std::cout << "Result: " << _stack.top() << std::endl;
}
