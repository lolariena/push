/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:58:34 by aibonade          #+#    #+#             */
/*   Updated: 2024/02/08 15:48:39 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_rotate(t_list **l)
{
	t_list	*tmp;

	if (!(*l)->next || !(*l))
		return ;
	tmp = *l;
	*l = (*l)->next;
	tmp->next = NULL;
	ft_lstadd_back(l, tmp);
}

void	ft_ra(t_list **l)
{
	ft_rotate(l);
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **l)
{
	ft_rotate(l);
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
