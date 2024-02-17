/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:31:53 by aibonade          #+#    #+#             */
/*   Updated: 2024/02/17 16:09:42 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

void    push_swap(t_list a);

//Parsing
//void	ft_lstdel(void *content);
void	ft_error();//free avant de l'appeler ! (pour le moment en tout cas)
t_list	*ft_create_a(char **av, int ac);

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
