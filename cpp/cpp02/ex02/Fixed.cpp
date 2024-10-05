/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:41:10 by romain            #+#    #+#             */
/*   Updated: 2024/10/05 16:33:09 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed&	Fixed::operator=(const Fixed& obj)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = obj.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &obj) const
{
	return (this->_rawBits > obj.getRawBits());
}

bool	Fixed::operator<(const Fixed &obj) const
{
	return (this->_rawBits < obj.getRawBits());
}

bool	Fixed::operator>=(const Fixed &obj) const
{
	return (this->_rawBits >= obj.getRawBits());
}

bool	Fixed::operator<=(const Fixed &obj) const
{
	return (this->_rawBits <= obj.getRawBits());
}

bool	Fixed::operator!=(const Fixed &obj) const
{
	return (this->_rawBits != obj.getRawBits());
}

bool	Fixed::operator==(const Fixed &obj) const
{
	return (this->_rawBits == obj.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &obj) const
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &obj) const
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &obj) const
{
	return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_rawBits++;
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_rawBits--;
	return (tmp);
}

Fixed::Fixed(void) : _rawBits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_rawBits = value << Fixed::_fractionalBits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(value * (1 << Fixed::_fractionalBits));
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (1 << Fixed::_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_rawBits >> Fixed::_fractionalBits);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}
