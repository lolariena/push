/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:31:53 by aibonade          #+#    #+#             */
/*   Updated: 2024/03/16 17:31:59 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

void	ft_push_swap(t_list **a);

//Parsing
void	ft_error(void);
t_list	*ft_create_a(char **av, int ac);
int		ft_check_error_atoi(const char *nptr);
int		ft_check_n(int *n, t_list **a, char *str);

//tri
int		ft_check_sort(t_list *a, int ordr);

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
