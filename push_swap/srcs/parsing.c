/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 23:22:28 by aibonade          #+#    #+#             */
/*   Updated: 2024/02/21 11:12:06 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>
int	ft_atoi_with_error(const char *nptr)//ajouter check int min & max //cest ici que ca merdouille
{
	int	n;
	int	sign;
	int	i;

printf("bbasuiufhiahihfuh str = %s\n", nptr);
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
printf("str = %s\n", nptr);
printf("La, n = %d\n", n);
		if (n >= 21484736 && (nptr[i] > '7' + sign))
			return (0);
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	if (nptr[i] && !ft_isdigit(nptr[i]))
		return (0);
	return (n * sign);
}


int	ft_check_error_atoi(const char *nptr)
{
	int	i;
	int nb_nondigit;

	i = 0;
	//while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
	//	i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
printf("Tsoin\n");
	nb_nondigit = i;//(nb ?)
printf("nondigit = %d\n", nb_nondigit);
	while (ft_isdigit(nptr[i]))
		i++;
printf("Tsoin\n");
	if ((nptr[i] && !ft_isdigit(nptr[i])) || ((i - nb_nondigit) > 1))
	{
printf("Tsoin\n");
		return (1);
	}
	return (0);
}

static int	ft_check_unique(t_list *a, int n)
{
	t_list *tmp;

	tmp = a;
	while (tmp)
	{
		if(*(int *)(tmp->content) == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
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

static int	ft_check_n(int n, t_list **a, char *str)
{
	printf("Tagada\n");
	if (!n && ft_check_error_atoi(str))
	{
printf("Bip n = %d\n", n);
		ft_lstclear(a, &free);
		return (1);
	}
printf("Tagada\n");
	if(a && ft_check_unique(*a, n))
	{
printf("Glagla\n");
		ft_lstclear(a, &free);
		return (1);
	}
	printf("Tagada\n");
	return (0);
}

t_list	*ft_create_a(char **av, int ac)//soit je fais deux sous-fonctions, soit une mais faut que je compte le nombre de chaines que j'ai au final si ac = 2 => je crois que ca tient en 24 lignes tout pile de faire
{
	int	i;
	int *n;
	t_list	*a;
	t_list	*new;
	//void fct(void *) = &free
	
	a = NULL;
	i = 0;//21/02 etait a -1
printf("ac = %d\n", ac);
	if (ac == 2)
	{
		ac = 0;//je peux gagner des lignes la en cherchant la taille de av avec une fonction separee, ca eviterait le moche ++i d'en bas
		while (av[ac])
			ac++;
		// while (av[i])
		// {
		// 	n = malloc(sizeof(int));
		// 	if (ft_freelst(n, &a));
		// 		return (NULL);
		// 	*n = ft_atoi_with_error(av[i]);//retourne 0 en cas d'erreur
		// 	if(ft_check_n(n, &a, av[i]))
		// 		return (NULL);
		// 	new = ft_lstnew(n);
		// 	if (ft_freelst(new, &a));
		// 		return (NULL);
		// 	ft_lstadd_back(&a, new);
		// 	i++;
		// }
		// return (a);
	}
//printf("str = %s\n", av[i]);
printf("ac = %d\n", ac);
	while (++i < ac)//erreur
	{
			n = malloc(sizeof(int));
			if (ft_freelst(n, &a))
				return (NULL);
			*n = ft_atoi_with_error(av[i]);//retourne 0 en cas d'erreur
			if(ft_check_n(*n, &a, av[i]))
				return (NULL);
printf("MAIIIIIIS\n");
			new = ft_lstnew(n);
			if (ft_freelst(new, &a))
				return (NULL);
			ft_lstadd_front(&a, new);
	}
	return (a);
}
