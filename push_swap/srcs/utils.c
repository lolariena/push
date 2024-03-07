/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:47:48 by aibonade          #+#    #+#             */
/*   Updated: 2024/02/26 14:10:02 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//0 pour ordre croissant, nawak autre pour decroissant
int	ft_check_sort(t_list *a, int ordr)
{
	t_list	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (ordr == 0 && *(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		else if (ordr != 0 && *(int *)tmp->content < *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
