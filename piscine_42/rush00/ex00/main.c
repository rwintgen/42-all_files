/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-lang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 09:40:23 by ede-lang          #+#    #+#             */
/*   Updated: 2023/09/25 08:34:41 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	rush(int l, int h);

int	ft_char_int(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')//tant qu'on est pas a la fin de la string
	{
		if (str[i] <= 57 && str[i] >= 48)//si le contenu de la case i est entre 0 et 9
			result = result * 10 + (str[i] - 48);//on stocke dans l'int result 10x la case i auquel on ajoute la case i
		else
			return (0);//sinon on met fin a la fonction
		i++;//on passe a la case suivante
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)// si on a 3 arguments (a,out, arg1, arg2 - on ecrit ca pour pas que argc soit unused)
		rush(ft_char_int(argv[1]), ft_char_int(argv[2])); //on envoie nos 2 stringd externes dans notre fonction rush
	return (0);
}
