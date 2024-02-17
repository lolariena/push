/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:31:53 by aibonade          #+#    #+#             */
/*   Updated: 2024/02/08 17:56:35 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"

void    push_swap(t_list a);

//Parsing
//void	ft_lstdel(void *content);

//Commandes
void	ft_sa(t_list *a);
void	ft_sb(t_list *b);
void	ft_ss(t_list *a, t_list *b);
void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **b, t_list **a);
void	ft_ra(t_list **l);
void	ft_rb(t_list **l);
void	ft_rr(t_list **a, t_list **b);
void	ft_rra(t_list **l);
void	ft_rrb(t_list **l);
void	ft_rrr(t_list **a, t_list **b);

#endif
