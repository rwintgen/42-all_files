/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:57:20 by romain            #+#    #+#             */
/*   Updated: 2024/08/20 16:03:46 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	public:
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();

		Bureaucrat	&operator=(Bureaucrat const &src);

		std::string const	&getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &form);
		void				executeForm(AForm const &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Grade is too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Grade is too low");
				}
		};

		class EmptyNameException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Name is empty");
				}
		};

	private:
		std::string const	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &obj);

#endif