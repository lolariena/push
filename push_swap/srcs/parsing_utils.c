/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:46:11 by aibonade          #+#    #+#             */
/*   Updated: 2024/02/26 13:46:19 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_error_atoi(const char *nptr)
{
	int	i;
	int	nb_nondigit;

	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	nb_nondigit = i;
	if (!nptr[i])
		return (1);
	while (ft_isdigit(nptr[i]))
		i++;
	if ((nptr[i] && !ft_isdigit(nptr[i])) || ((i - nb_nondigit) >= 10))
	{
		if (!nptr[i] && ((i - nb_nondigit) == 10))
		{
			if (nptr[0] == '-' && nptr[i - 1] <= '8')
				return (0);
			if ((nptr[0] == '+' || ft_isdigit(nptr[0])) && nptr[i - 1] < '8')
				return (0);
		}
		return (1);
	}
	return (0);
}

static int	ft_check_unique(t_list *a, int n)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		if (*(int *)(tmp->content) == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_n(int n, t_list **a, char *str)
{
	if (!n && ft_check_error_atoi(str))
	{
		ft_lstclear(a, &free);
		return (1);
	}
	if (a && ft_check_unique(*a, n))
	{
		ft_lstclear(a, &free);
		return (1);
	}
	return (0);
}