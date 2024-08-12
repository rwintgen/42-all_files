/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:41:13 by romain            #+#    #+#             */
/*   Updated: 2024/08/12 13:04:19 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed&	operator=(const Fixed &obj);
		
		Fixed(void);
		Fixed(const Fixed &src);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};

#endif