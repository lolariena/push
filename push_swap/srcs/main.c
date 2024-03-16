/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:19:50 by aibonade          #+#    #+#             */
/*   Updated: 2024/03/16 17:14:49 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include "stdio.h"

int	main(int ac, char **av)
{
	int		i;
	t_list	*a;
//t_list *suppr;

	if (ac < 2)
		return (0);
//deplacer tout ca dans une autre fonction (create a du coup ?)
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (!av)
			ft_error();
		a = ft_create_a(av, ac);
		i = 0;
		while (av[i])//voir a faire une ft_free plus propre ?
			free(av[i++]);
		free(av);
	}
	else
		a = ft_create_a(av, ac);
	if (!a)
		ft_error();
	if (ft_check_sort(a, 0))
	{
		ft_lstclear(&a, &free);
		return (0);
	}
printf("Liste non triee, on continue !\n");//a supprimer in fine
/* afficher la liste
i = 0;
suppr = a;
while (suppr)
{
	printf("a%d = %d\n", i, *(int*)(suppr->content));
	i++;
	suppr = suppr->next;
}*/
//gerer si a ne contient que 2 elements faire juste un ra (si on arrive la cest aue cest pas trie)
	ft_push_swap(&a);//&a
	ft_lstclear(&a, &free);
	return (0);
}
