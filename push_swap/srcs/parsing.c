/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 23:22:28 by aibonade          #+#    #+#             */
/*   Updated: 2024/02/26 13:44:37 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_test_minmax(int n, char c, int sign)
{
	if (n > 214748364)
		return (1);
	if (n == 214748364)
	{
		if ((c > '7' && sign > 0) || (c > '8' && sign < 0))
			return (1);
	}
	return (0);
}

int	ft_atoi_with_error(const char *nptr)
{
	int	n;
	int	sign;
	int	i;

	n = 0;
	sign = 1;
	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		if (ft_test_minmax(n, nptr[i], sign))
			return (0);
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	if (nptr[i] && !ft_isdigit(nptr[i]))
		return (0);
	return (n * sign);
}

static int	ft_freelst(void *n, t_list **a)
{
	if (!n)
	{
		ft_lstclear(a, &free);
		return (1);
	}
	return (0);
}

static int	ft_avsize(char **av, int *ac)
{
	if (*ac == 2)
	{
		*ac = 0;
		while (av[*ac])
			*ac += 1;
		return (0);
	}
	return (1);
}

t_list	*ft_create_a(char **av, int ac)
{
	int		i;
	int		*n;
	t_list	*a;
	t_list	*new;

	a = NULL;
	i = ft_avsize(av, &ac);
	while (i < ac)
	{
		n = malloc(sizeof(int));
		if (ft_freelst(n, &a))
			return (NULL);
		*n = ft_atoi_with_error(av[i]);
		if (ft_check_n(*n, &a, av[i]))
			return (NULL);
		new = ft_lstnew(n);
		if (ft_freelst(new, &a))
			return (NULL);
		ft_lstadd_back(&a, new);
		i++;
	}
	return (a);
}
