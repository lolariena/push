/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 23:22:28 by aibonade          #+#    #+#             */
/*   Updated: 2024/02/08 18:10:30 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_with_error(const char *nptr)//ajouter check int min & max
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
		if (n >= 21484736 && (nptr[i] > '7' + sign))
			return (0);
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	if (nptr[i] && !ft_isdigit(nptr[i])
		return (0);
	return (n * sign);
}


int	ft_check_error_atoi(const char *nptr)
{
	int	i;
	int nb_nondigit;

	i = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	nb = i;
	nb_nondigit;
	while (ft_isdigit(nptr[i]))
		i++;
	if ((nptr[i] && !ft_isdigit(nptr[i]) || (i - nb_nondigit) > 1))
		return (1);
	return (0);
}

t_list	ft_create_a(char **av, int ac)
{
	int	i;
	int n;
	t_list	*a;
	t_list	*new;
	//void fct(void *) = &free;
	
	i = 0;
	if (ac == 2)
	{
		while (av[i])
		{
			n = ft_atoi_with_error(av[i]);//retourne 0 en cas d'erreur
			if (!n && ft_check_error_atoi(av[i]))
			{
				ft_lstclear(&a, &free)
				return (NULL);
			}
			new = ft_lstnew(n);
			ft_lstadd_back(&a, new);
			i++;
		}
		return (a);
	}
	while (ac)
	{
			n = ft_atoi_with_error(av[i]);//retourne 0 en cas d'erreur
			if (!n && ft_check_error_atoi(av[i]))
			{
				ft_lstclear(&a, &free)
				return (NULL);
			}
			new = ft_lstnew(n);
			ft_lstadd_front(&a, new);
			i++;
	}
}
