/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:56:06 by romain            #+#    #+#             */
/*   Updated: 2024/08/21 13:13:45 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &src);
		
		std::string	getTarget() const;

		void			execute(Bureaucrat const &executor) const;
		static AForm	*create(std::string const &target);

	private:
		std::string	_target;
};

#endif