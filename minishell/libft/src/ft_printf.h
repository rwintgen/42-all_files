/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:47:12 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/13 02:10:55 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_printf_param(va_list args, char c);

size_t	ft_strlen(const char *s);

int		ft_printf_char(int c);
int		ft_printf_string(char *str);
int		ft_printf_decimal(int nb);
int		ft_printf_unsigned_decimal(unsigned int nb);
int		ft_printf_hex_address(void *ptr);
char	*ft_itoa(int n);

int		ft_putnbr_base(unsigned long long nb, char *base);
int		ft_putchar(char c);
#endif