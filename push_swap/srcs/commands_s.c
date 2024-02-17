/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:56:45 by aibonade          #+#    #+#             */
/*   Updated: 2024/02/08 15:37:20 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap(t_list *a)
{
	void	*tmp;

	if (!a)
		return ;
	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
}

void	ft_sa(t_list *a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_list *a)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_list *a, t_list *b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
