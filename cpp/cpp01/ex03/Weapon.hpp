/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:12:46 by romain            #+#    #+#             */
/*   Updated: 2024/07/25 13:26:10 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class	Weapon
{
	public:
		Weapon(void);
		Weapon(std::string type);

		const std::string&	getType();
		void				setType(std::string type);
	private:
		std::string	_type;
};

#endif
