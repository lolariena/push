/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:04:13 by aibonade          #+#    #+#             */
/*   Updated: 2024/03/21 18:04:18 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_fill_tab(t_list *a, int *tab, int size_tab)//a mettre dans ps_utils et garder static
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
			if ((i < size_tab - 1)
				&& *(int *)tmp->content > max
				&& *(int *)tmp->content < tab[i + 1])
				max = *(int *)tmp->content;
			else if ((i == size_tab - 1) && *(int *)tmp->content > max)
				max = *(int *)tmp->content;
			tmp = tmp->next;
		}
		tab[i] = max;
	}
}

static int	*ft_init_tab(t_list *a)//a mettre dans ps_utils et virer static
{
	int		*tab;
	int		size;

	size = ft_lstsize(a);
	tab = malloc(size * sizeof(int));
	if (!tab)
		return (NULL);
	ft_fill_tab(a, tab, size);
	return (tab);
}

static int	ft_calculation_nb_move(int *ordered, int to_sort, int current_place, int size)
{
	int	i;
	int	nb_move;

	nb_move = 0;
	i = 0;
	while (i < size && ordered[i] != to_sort)
		i++;
	if (current_place < i)//je me suis plantee la : il faut probablement faire le calcul en fonction de sa place dans ordonne, ex : current place - i <= 2 * size / 3 => mais du coup ca depend de si i > ou < a current avant  : <= ((2 * size) / 3 
		nb_move = (i - current_place) * 2;
	else
		nb_move = (current_place - i) * 2;
	if (current_place > size / 2)
		nb_move += size - current_place;
	else
		nb_move += current_place; 
	return (nb_move);
}

static void	ft_update_current(t_data data, t_list *l, int start)//pb : liste pas forcement dans le bon ordre... enfin elle se decale quoi, comment gerer la boucle sachant quon a un null au milieu ? sachant que la je sais que mon max et mon min sont bien places ils peuvent me servir de reperes en fait...
{
	int		i;
	t_list	*tmp;

	tmp = l;
	while (*(int *)tmp->content != start)
		tmp = tmp->next;
	i = 0;
	while (i < data->current_size)
	{
		if (*(int *)tmp->content == data->good_order[i])
			data->current_order[i] = 0;
		else
			data->current_order[i] = ft_calculation_nb_move(data->good_order, *(int *)tmp->content, i, data->current_size);//calculer le nb de mv a faire pour le mettre a la bonne place...
		if (tmp->next)
			tmp = tmp->next;
		else
			tmp = l;
		i++;
	}
}

int	ft_which_one_moves(t_data *data)
{
	int	i;
	//int	min_move;
	int	save_index;

	i = 0
	save_index = 0;
	data->min_move = 2147483647;//est-ce assez grand ?
	while (i < size)
	{
		if (data->current_order[i] != 0 && data->current_order[i] < data->min_move)
		{
			data->min_move = data->current_order[i];
			save_index = i;
		}
		i++;
	}
	return (save_index);
}

void	ft_sort_one(t_list **to_sort, int current_index, t_list **l2, t_data data)//pour reduire utiliser ***t_list oui mais j'ai aussi besoin de lordre... ou en tout cas de l'index correct => va falloir que je me cree une struct specifique...
{
	int	nb_rotations;
	int	nb_swaps;
	int i;
	int	good_index;

	i = 0;
	if (current_index > data->current_size / 2)
	{
		nb_rotations = data->current_size - current_index;//la aussi du coup (ligne)
		while (i < nb_rotations)//sinon faire une fonction binaire soit rb soit rrb sur toute la boucle
		{
			ft_rrb(to_sort);//rrr ???
			i++;
		}
	}
	else
	{
		nb_rotations = current_index;//on peut gagner une ligne la si besoin
		while (i < nb_rotations)
		{
			ft_rb(to_sort);//rr ?
			i++;
		}
	}
	i = 0;
	good_index = //LAAAAAAAAAAAAAAA
	if (index <= ((2 * data->current_size) / 3))
	{
		nb_swaps = (data->min_move - nb_rotations)/2;//a modifier si je passe plutot sur a
		while (i < nb_swaps)
		{
			if ()//ICIIIIIIIIIIIII
			ft_sb(to_sort);//ss?
			i++;
		}
	}
	else
		nb_swaps = (data->min_move - nb_rotations) / 2;
}

void	ft_sort2(t_list **to_sort, t_list **l2, t_data *data)
{
	int	index;
	//int size;

	//size = ft_lstsize(to_sort);
	while (!ft_check_sort(*to_sort, 1))//comment je sais que c'est a ou b ? pour l'instant CB (:nerd:)
	{
		ft_update_current(data, *to_sort, data->good_order[0]);
		ft_sort_one(to_sort, ft_which_one_moves(data), l2, data);
	}
}

void	ft_sort(t_list **to_sort, t_list **l2)//Si on utilise aussi pour a, penser a preinstaller quand meme correctement le min (ou le max)
{
	//int *good_order;
	//int *current_order;
	//int size;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return ;//voir plus bas
	data->current_size = ft_lstsize(*to_sort);
	data->good_order = ft_init_tab(*to_sort);
	if (!data->good_order)
	{
		ft_free_data(data);
		return ;//si malloc pas bon comment on arrete ? valeur de retour ? putain de migraine de meeeeeeerdeeeeeeuh
	}
	data->current_order = malloc(size * sizeof(int));
	if (!data->current_order)
	{
		ft_free_data(data);
		return ;//idem
	}
	//ft_update_current(good_order, current_order, size, good_order[0])//check ordre dans good order => doit etre decroissant
	ft_sort2(to_sort, l2, data);
	ft_free_data(data);
}
