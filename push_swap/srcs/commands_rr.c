/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:19:05 by aibonade          #+#    #+#             */
/*   Updated: 2024/03/16 17:12:14 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_reverse_rotate(t_list **l)
{
	t_list	*tmp;
	int		size;

	size = ft_lstsize(*l);
	if (size < 2)
		return ;
	tmp = ft_lstlast(*l);
	ft_lstadd_front(l, tmp);
	tmp = *l;
	while (size > 1)
	{
		tmp = tmp->next;
		size--;
	}
	tmp->next = NULL;
}

void	ft_rra(t_list **l)
{
	ft_reverse_rotate(l);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **l)
{
	ft_reverse_rotate(l);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
