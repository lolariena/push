/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:57:20 by aibonade          #+#    #+#             */
/*   Updated: 2024/03/16 17:11:39 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_push(t_list **l1, t_list **l2)
{
	t_list	*tmp;

	if (!l2)
		return ;
	tmp = *l2;
	*l2 = (*l2)->next;
	ft_lstadd_front(l1, tmp);
}

void	ft_pa(t_list **a, t_list **b)
{
	ft_push(a, b);
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **b, t_list **a)
{
	ft_push(b, a);
	write(1, "pb\n", 3);
}
