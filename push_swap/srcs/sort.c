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
	if (current_place <= ((2 * size) / 3))
		nb_move = i - current_place; //a finir !!!!ICIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
	return ();
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

void	ft_sort(t_list **to_sort, t_list **l2)//Si on utilise aussi pour a, penser a preinstaller quand meme correctement le min (ou le max)
{
	int *good_order;
	int *current_order;
	int size;
	int	start;

	size = ft_lstsize(a);
	good_order = ft_init_tab(*to_sort);
	if (!good_order)
		return ;//si malloc pas bon comment on arrete ? valeur de retour ? putain de migraine de meeeeeeerdeeeeeeuh
	current_order = malloc(size * sizeof(int));
	if (!current_order)
	{
		free(good_order);
		return ;//idem
	}

	free(current_order);
	free(order);
}