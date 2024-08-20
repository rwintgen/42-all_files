/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:12:18 by romain            #+#    #+#             */
/*   Updated: 2024/08/20 16:18:25 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &src);
		
		void		execute(Bureaucrat const &obj) const;
		std::string	getTarget() const;
	private:
		std::string	_target;
};

#endif