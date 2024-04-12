/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:25:59 by rwintgen          #+#    #+#             */
/*   Updated: 2023/10/08 19:43:29 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_function.h"
#include <stdlib.h>
#include <unistd.h>

int		*ft_store_int(char *str);
char	**ft_store_str(char *str);
void	ft_print_num(long int num, int *tab, char **dict);
int		islegit(int argc, char **argv);
void	print_numbers(long int nb, char *path);
char	*ft_read_file(char *path);
void	free_tab_char(char **tab_char, int size);

int	main(int argc, char **argv)
{
	long int	argvint;

	argvint = 0;
	if (islegit(argc, argv) == 0)
	{
		if (argc == 2)
		{
			argvint = ft_atoi_2(argv[1]);
			print_numbers(argvint, "numbers.dict");
		}
		else if (argc == 3)
		{
			argvint = ft_atoi_2(argv[2]);
			print_numbers(argvint, argv[1]);
		}
	}
	else
		ft_putstr("Error\n");
	return (0);
}

void	print_numbers(long int nb, char *path)
{
	char	**tab_char;
	int		*tab_int;
	char	*str;
	int		size;

	str = ft_read_file(path);
	if (str == NULL)
		ft_putstr("Dict Error\n");
	else
	{
		size = ft_count_lines(str);
		tab_char = ft_store_str(str);
		tab_int = ft_store_int(str);
		ft_print_num(nb, tab_int, tab_char);
		write(1, "\n", 1);
		free_tab_char(tab_char, size);
		free(tab_int);
		free(str);
	}
}

void	free_tab_char(char **tab_char, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab_char[i]);
		i++;
	}
	free(tab_char);
}
