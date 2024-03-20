/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sort.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aibonade <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/03/17 13:27:48 by aibonade		  #+#	#+#			 */
/*   Updated: 2024/03/17 13:27:55 by aibonade		 ###   ########.fr	   */
/*																			*/
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

static void	ft_update_current(int *ordered, int *current, int size, t_list *l, int start)//pb : liste pas forcement dans le bon ordre... enfin elle se decale quoi, comment gerer la boucle sachant quon a un null au milieu ? sachant que la je sais que mon max et mon min sont bien places ils peuvent me servir de reperes en fait...
{
	int		i;
	t_list	*tmp;

	tmp = l;
	while (*(int *)tmp->content != start)
		tmp = tmp->next;
	i = 0;
	while (i < size)
	{
		if (*(int *)tmp->content == ordered[i])
			current[i] = 0;
		else
			current[i] = ft_calculation_nb_move(ordered, *(int *)tmp->content, i, size);//calculer le nb de mv a faire pour le mettre a la bonne place...
		if (tmp->next)
			tmp = tmp->next;
		else
			tmp = l;
		i++;
	}
}

int	ft_which_one_moves(int *current, int size)
{
	int	i;
	int	min_move;
	int	save_index;

	i = 0
	save_index = 0;
	min_move = 2147483647;//est-ce assez grand ?
	while (i < size)
	{
		if (current[i] != 0 && current[i] < min_move)
		{
			min_move = current[i];
			save_index = i;
		}
		i++;
	}
	return (save_index);
}

void	ft_sort_one(t_list **to_sort, int index, t_list **l2, int size, int nb_moves)//pour reduire utiliser **t_list oui mais j'ai aussi besoin de lordre... ou en tout cas de l'index correct => va falloir que je me cree une struct specifique...
{
	int	nb_rotations;
	int	nb_swaps;
	int i;

	i = 0;
	if (current_place > size / 2)
	{
		nb_rotations = size - index;//la aussi du coup
		while (i < nb_rotations)//sinon faire une fonction binaire soit rb soit rrb sur toute la boucle
		{
			ft_rrb(to_sort);//rrr ???
			i++;
		}
	}
	else
	{
		nb_rotations = index;//on peut gagner une ligne la si besoin
		while (i < nb_rotations)
		{
			ft_rb(to_sort);//rr
			i++;
		}
	}
	i = 0;
	if (index <= ((2 * size) / 3))
	{
		nb_swaps = nb_moves - nb_rotations;
		while (i < nb_swaps)
		{
			ft_sb//PAR ICIIIIIIIIIIIIIIIIIIIIII !
			i++;
		}
	}
	else
		nb_swaps = (nb_moves - nb_rotations) / 2;
}

void	ft_sort2(t_list **to_sort, t_list **l2, int *current_order, int *good_order)
{
	int	index;
	int size;

	size = ft_lstsize(to_sort);
	while (!ft_check_sort(to_sort, 1))//comment je sais que c'est a ou b ? pour l'instant CB (:nerd:)
	{
		ft_update_current(good_order, current_order, size, good_order[0]);
		ft_sort_one(to_sort, ft_which_one_moves(current_order, size), l2, size);
	}
}

void	ft_sort(t_list **to_sort, t_list **l2)//Si on utilise aussi pour a, penser a preinstaller quand meme correctement le min (ou le max)
{
	int *good_order;
	int *current_order;
	int size;

	size = ft_lstsize(to_sort);
	good_order = ft_init_tab(*to_sort);
	if (!good_order)
		return ;//si malloc pas bon comment on arrete ? valeur de retour ? putain de migraine de meeeeeeerdeeeeeeuh
	current_order = malloc(size * sizeof(int));
	if (!current_order)
	{
		free(good_order);
		return ;//idem
	}
	//ft_update_current(good_order, current_order, size, good_order[0])//check ordre dans good order => doit etre decroissant
	ft_sort2(to_sort, l2, current_order, good_order);
	free(current_order);
	free(order);
}