/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:19:50 by aibonade          #+#    #+#             */
/*   Updated: 2024/01/31 01:19:09 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/libft/libft.h"

int	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
		return (0);
//deplacer tout ca dans une autre fonction (create a du coup ?)
	if (ac == 2)
	{
		av = ft_split(av[1], 1);
		if (!av)
			//error; fonction d'erreur qui print error, libere tout et exit ? a voir
		a = ft_create_a(av, ac);//si ac = 2 => Tant que av, add back + Si pb penser a free av !!!!
		i = 0;
		while (av[i])//voir a faire une ft_free plus propre ?
			free(av[i++]);
		free(av);
	}
	else
		a = ft_create_a(av, ac);//si ac > 2 => Tant que ac, add front
	if (!a)
		//error;
	//creer pile a => liste chainee ? // =>verifier qu'elle n'a pas deux fois le meme chiffre au moment d'implementer la pile (a chaque creation d'un nouveau maillon) + parsing 
	//verifier si elle est deja triee ou =1 => Si oui, exit ! 
	//push_swap(&a)
	//free a ? => faudra free a chaque erreur donc... print error et free a puis exit ?
	return (0);
}
