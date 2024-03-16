/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:32:17 by aibonade          #+#    #+#             */
/*   Updated: 2024/03/16 17:29:33 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

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
			if ((i < size_tab - 1)
				&& *(int *)tmp->content > max
				&& *(int *)tmp->content < tab[i + 1])
				max = *(int *)tmp->content;
			else if ((i == size_tab - 1) && *(int *)tmp->content > max)
				max = *(int *)tmp->content;
			tmp = tmp->next;
		}
		tab[i] = max;
	}
}

static int	*ft_init_tab(t_list *a)
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

static int	ft_median(t_list *a, int *tab)
{
	int size;

	size = ft_lstsize(a);
	if (size % 2)
		return (tab[size / 2]);
	return ((tab[size / 2] + tab[size / 2 - 1]) / 2);
}

static void	ft_presort(t_list **a, t_list **b, int minmax[2])//a mettre dans utils ps + couper !
{
	if (*(int *)(*a)->content > minmax[0])
	{
		if (*(int *)(*a)->content < minmax[1])
		{
			if (*b && *(int *)(*b)->content == minmax[1])
			{
				ft_pb(b, a);
				ft_sb(*b);//on peut opti avec rb et rrb ?
			}
			else
				ft_pb(b, a);
		}
		else
		{
			if (*b && *(int *)(*b)->content != minmax[1])
				ft_rrb(b);
			minmax[1] = *(int *)(*a)->content;
			ft_pb(b, a);
		}
	}
	else
	{
		if (*b && *(int *)(*b)->content != minmax[1])
			ft_rrb(b);
		minmax[0] = *(int *)(*a)->content;
		ft_pb(b, a);
		ft_rb(b);//rotate_ab?
	}
}

static void	ft_init_minmax(int minmax[2], t_list **b)
{
	if (*(int *)(*b)->content > *(int *)(*b)->next->content)
	{
		minmax[0] = *(int *)(*b)->next->content;
		minmax[1] = *(int *)(*b)->content;
	}
	else
	{
		minmax[0] = *(int *)(*b)->content;
		minmax[1] = *(int *)(*b)->next->content;
		ft_rb(b);//rotate_ab ?
	}
}
//trop de fonctions ici !
static void	ft_cut(t_list **a, t_list **b, int median)//trop longue !
{
	int		stop;
	int		count_stop;
	int		minmaxb[2];
	int		push2;
	t_list	*tmp;

	tmp = *a;
	while (*(int *)tmp->content <= median)
		tmp = tmp->next;
	stop = *(int *)tmp->content;
	count_stop = 0;
	push2 = 0;
	while (count_stop <= 1)
	{
		if (*(int *)(*a)->content == stop)
			count_stop++;
		if (count_stop <= 1)
		{
			if (*(int *)(*a)->content <= median)
			{
				if (push2 < 2)
				{
					ft_pb(b, a);
					if (push2 == 1)
						ft_init_minmax(minmaxb, b);
					push2++;
				}
				else
					ft_presort(a, b, minmaxb);
			}
			else
				ft_ra(a);
		}
	}
}

void	ft_push_swap(t_list **a)
{
	t_list	*b;
	int		*tab;
	int		i;
	int		median;
	//int	size;//suppr
	t_list	*tmp,*tmp2;//suppr
	int 	j;//suppr

	b = NULL;
	tab = ft_init_tab(*a);
	if (!tab)
		return ;
	median = ft_median(*a, tab);
/*rintf("mediane = %d\n", median);
size = ft_lstsize(*a);
i = 0;
while (i < size)
{
	printf("%d\n", tab[i]);
	i++;
}*/
	ft_cut(a, &b, median);

tmp = *a;
tmp2 = b;
while(tmp || tmp2)
	{
		if (tmp)
		{
			i = *(int *)tmp->content;
			printf("a : %d    ",i);
			tmp = tmp->next;
		}
		else
			printf("         "); 
		if (tmp2)
		{
			j = *(int *)tmp2->content;
			printf("b : %d", j);
			tmp2 = tmp2->next;
		}
		printf("\n");
	}
	free (tab);
}

