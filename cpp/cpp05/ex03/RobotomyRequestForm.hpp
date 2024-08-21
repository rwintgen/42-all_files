/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:09 by romain            #+#    #+#             */
/*   Updated: 2024/08/21 13:15:24 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &src);
		
		std::string	getTarget() const;

		void			execute(Bureaucrat const &executor) const;
		static AForm	*create(std::string const &target);


	private:
		std::string	_target;
};

#endif