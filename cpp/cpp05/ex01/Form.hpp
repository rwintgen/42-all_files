/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:36:08 by romain            #+#    #+#             */
/*   Updated: 2024/10/30 16:33:58 by rwintgen         ###   ########.fr       */
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
		~Form(void);

		Form	&operator=(Form const &src);
		
		std::string	getName(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		bool		isSigned(void) const;
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
		Form();
		
		std::string const	_name;
		int const			_signGrade;
		int const			_execGrade;
		bool				_signed;
};

std::ostream	&operator<<(std::ostream &out, Form const &form);

#endif