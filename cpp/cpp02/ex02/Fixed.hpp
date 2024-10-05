/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:41:13 by romain            #+#    #+#             */
/*   Updated: 2024/10/05 16:29:04 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed&	operator=(const Fixed &obj);

		bool	operator>(const Fixed &obj) const;
		bool	operator<(const Fixed &obj) const;
		bool	operator>=(const Fixed &obj) const;
		bool	operator<=(const Fixed &obj) const;
		bool	operator!=(const Fixed &obj) const;
		bool	operator==(const Fixed &obj) const;

		Fixed	operator+(const Fixed &obj) const;
		Fixed	operator-(const Fixed &obj) const;
		Fixed	operator*(const Fixed &obj) const;
		Fixed	operator/(const Fixed &obj) const;

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed&		min(Fixed &a, Fixed &b);
		static const Fixed&	min(const Fixed &a, const Fixed &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static const Fixed&	max(const Fixed &a, const Fixed &b);

	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream &out, const Fixed &obj);

#endif
