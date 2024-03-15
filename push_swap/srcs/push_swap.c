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
static int	ft_median(t_list *a, int *tab)
{
	int size;

	size = ft_lstsize(a);
	if (size % 2)
		return (tab[size / 2]);
printf("size = %d\nsize / 2 = %d\ntab[size / 2] = %d\ntab[size / 2 - 1] = %d\n(tab[size / 2] + tab[size / 2 - 1]) / 2 = %d\n\n", size, size / 2, tab[size / 2], tab[size / 2 - 1], (tab[size / 2] + tab[size / 2 - 1]) / 2);
	return ((tab[size / 2] + tab[size / 2 - 1]) / 2);
}

static void	ft_presort(t_list **a, t_list **b, int *min, int *max)//a mettre dans utils ps
{
printf("-----\n");
printf("element = %d\n", *(int *)(*a)->content);
	if (*(int *)(*a)->content >= *min)
	{
		if (*(int *)(*a)->content < *max)
		{
			if (*b && *(int *)(*b)->content == *max)
			{
				ft_pb(b, a);
				ft_sb(*b);
			}
			else
				ft_pb(b, a);
		}
		else
		{
			if (*b && *(int *)(*b)->content != *max)
				ft_rrb(b);
			*max = *(int *)(*a)->content;
			ft_pb(b, a);
		}
	}
	else
	{
printf("Poeut\n");
		if (*b && *(int *)(*b)->content != *max)
			ft_rrb(b);
		*min = *(int *)(*a)->content;
		ft_pb(b, a);
		ft_rb(b);//rotate_ab?
	}
printf("-----\n");
printf("-----\n");
}

static void	ft_init_minmax(int *min, int *max, t_list **b)
{
	if (*(int *)(*b)->content < *(int *)(*b)->next->content)
	{
		*min = *(int *)(*b)->next->content;
		*max = *(int *)(*b)->content;
		//ft_rb(b);//rotate_ab ?
	}
	else
	{
		*min = *(int *)(*b)->content;
		*max = *(int *)(*b)->next->content;
	}
}

static void	ft_cut(t_list **a, t_list **b, int median)
{
	int		stop;
	int		count_stop;
	int 	minb;//passer en tableau avec max
	int 	maxb;
	int		push2;
	t_list	*tmp;

	//maxb = -2147483648;
	//minb = 2147483647;
	tmp = *a;
	while (*(int *)tmp->content <= median)
		tmp = tmp->next;
	stop = *(int *)tmp->content;
	count_stop = 0;
	//tmp = a;
	push2 = 0;
	while (count_stop <= 1)
	{
		if ( *(int *)(*a)->content == stop)
			count_stop++;
		if (count_stop <= 1)
		{
			if(*(int *)(*a)->content <= median)
			{
				if (push2 < 2)
				{
					ft_pb(b, a);
					if (push2 == 1)
						ft_init_minmax(&minb, &maxb, b);
					push2++;
				}
				else
					ft_presort(a, b, &minb, &maxb);
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
	int		median;//inclure la mediane dans le deplacement vers b au cas ou si jamais par ex -1 0 1 2 (mediane = 0.5 donc 0) 
	int		size;//a suppr
t_list *tmp,*tmp2;
int j;


	b = NULL;
	tab = ft_init_tab(*a);
	if (!tab)
		return ;
	median = ft_median(*a, tab);
printf("mediane = %d\n", median);
size = ft_lstsize(*a);
i = 0;
while (i < size)
{
	printf("%d\n", tab[i]);
	i++;
}
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

