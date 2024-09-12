/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:36:08 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:27:57 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm(std::string const &name, int signGrade, int execGrade);
		AForm(AForm const &copy);
		virtual ~AForm(void);

		AForm	&operator=(AForm const &src);
		
		std::string		getName(void) const;
		int				getSignGrade(void) const;
		int				getExecGrade(void) const;
		bool			isSigned(void) const;
		void			beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;

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

		class	FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Form is not signed");
				}
		};

		class	FileNotOpenException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("File could not be opened");
				}
		};
		
		class	InvalidFormException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Invalid form");
				}
		};

	private:
		std::string const	_name;
		int const			_signGrade;
		int const			_execGrade;
		bool				_signed;
};

std::ostream	&operator<<(std::ostream &out, AForm const &form);

#endif