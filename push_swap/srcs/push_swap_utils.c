/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:05:50 by aibonade          #+#    #+#             */
/*   Updated: 2024/03/16 17:18:53 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_ab(t_list *to_swap, t_list *other, char lst_ts)
{
	//test si besoin dans other en fonction de la liste donnee 'a' ou 'b'
	if (lst_ts == 'a')
		ft_sa(to_swap);
	else if (lst_ts == 'b')
		ft_sb(to_swap);
	//ft_ss(...); 
}

void	ft_rotate_ab(t_list *to_swap, t_list *other, char lst_ts)
{
	//test si besoin dans other en fonction de la liste donnee 'a' ou 'b'
	if (lst_ts == 'a')
		ft_ra(to_swap);
	else if (lst_ts == 'b')
		ft_rb(to_swap);
	//ft_rr(...); 
}

void	ft_rev_rotate_ab(t_list *to_swap, t_list *other, char lst_ts)
{
	//test si besoin dans other en fonction de la liste donnee 'a' ou 'b'
	if (lst_ts == 'a')
		ft_rra(to_swap);
	else if (lst_ts == 'b')
		ft_rrb(to_swap);
	//ft_rrr(...); 
}
