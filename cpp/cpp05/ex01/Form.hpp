/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:36:08 by romain            #+#    #+#             */
/*   Updated: 2024/08/20 15:06:18 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		Form(std::string const &name, int signGrade, int execGrade);
		Form(Form const &copy);
		~Form();

		Form	&operator=(Form const &src);
		
		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		isSigned() const;
		void		beSigned(Bureaucrat const &bureaucrat);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Grade is too high");
				}
		};
		
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Grade is too low");
				}
		};

		class	EmptyNameException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Name is empty");
				}
		};

		class	FormSignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Form is already signed");
				}
		};	
	private:
		std::string const	_name;
		int					_signGrade;
		int					_execGrade;
		bool				_signed;
};

std::ostream	&operator<<(std::ostream &out, Form const &form);

#endif