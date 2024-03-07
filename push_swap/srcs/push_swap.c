/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:32:17 by aibonade          #+#    #+#             */
/*   Updated: 2024/02/17 16:19:16 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	 "../includes/push_swap.h"

static void	ft_fill_tab(t_list *a, int *tab, int size_tab)
{
	t_list	*tmp;
	int		i;
	int		max;

	i = size_tab;
	while (i--)
	{
		tmp = a;
		max = -2147483648;
		while (tmp)
		{
			if ((i < size_tab - 1) &&
				*(int *)tmp->content > max && *(int *)tmp->content < tab[i + 1])
				max = *(int *)tmp->content;
			else if ((i == size_tab - 1) && *(int *)tmp->content > max)
				max = *(int *)tmp->content;
			tmp = tmp->next;
		}
		tab[i] = max;
	}
}

static int *ft_init_tab(t_list *a)
{
	int		*tab;
	int		size;

	size = ft_lstsize(a);
	tab = malloc(size * sizeof(int));//tester a 0
	if (!tab)
		return (NULL);
	ft_fill_tab(a, tab, size);

	return (tab);
}

#include "stdio.h"
void	ft_push_swap(t_list *a)
{
	t_list	*b;
	int		*tab;
	int		i;
	int		size;//a suppr


	b = NULL;
	tab = ft_init_tab(a);
	if (!tab)
		return ;

size = ft_lstsize(a);
i = 0;
while (i < size)
{
	printf("%d\n", tab[i]);
	i++;
}
	free (tab);
}

