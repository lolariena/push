#include "ft_printf/libft/libft.h"
#include <stdio.h>

static void	ft_swap(t_list *a)
{
	void	*tmp;

	if (!a)
		return ;

	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next)
		return (ft_lstlast(lst->next));
	return (lst);
}

void	ft_sa(t_list *a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_list *b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_list *a, t_list *b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_push(t_list **l1, t_list **l2)
{
	t_list	*tmp;
	
	if (!l2)
		return ;
	tmp = *l2;
	*l2 = (*l2)->next;
	ft_lstadd_front(l1, tmp);
}

void ft_pa(t_list **a, t_list **b)
{
	ft_push(a, b);
	write(1, "pa\n", 3);
}

void ft_pb(t_list **b, t_list **a)
{
	ft_push(b, a);
	write(1, "pb\n", 3);
}

void	ft_rotate(t_list **l)
{
	t_list	*tmp;

	if (!(*l)->next || !(*l))
		return ;
	tmp = *l;
	*l = (*l)->next;
	tmp->next = NULL;
	ft_lstadd_back(l, tmp);
}

void	ft_ra(t_list **l)
{
	ft_rotate(l);
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **l)
{
	ft_rotate(l);
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}

int	ft_lstsize(t_list *lst)
{
	if (!lst)
		return (0);
	if (lst->next)
		return (ft_lstsize(lst->next) + 1);
	return (1);
}

void	ft_reverse_rotate(t_list **l)
{
	t_list	*tmp;
	int		size;

	size = ft_lstsize(*l);
	if (size < 2)
		return ;
	tmp = ft_lstlast(*l);
	ft_lstadd_front(l, tmp);
	tmp = *l;
	while (size > 1)
	{
		tmp = tmp->next;
		size--;
	}
	tmp->next = NULL;
}

void	ft_rra(t_list **l)
{
	ft_reverse_rotate(l);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **l)
{
	ft_reverse_rotate(l);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}


int main()
{
	t_list	*a, *b, *tmp, *tmp2;
	int		A,B,C,D,E,F,G,H, i,j;

	A = 0;
	B = 1;
	C = 2;
	D = 3;
	E = 4;
	F = 5;
	G = 6;
	H = 7;
	a = ft_lstnew(&A);
	b = ft_lstnew(&E);
	tmp = ft_lstnew(&B);
	tmp2 = ft_lstnew(&F);
	ft_lstadd_back(&a, tmp);
	ft_lstadd_front(&b, tmp2);
	tmp = ft_lstnew(&C);
	tmp2 = ft_lstnew(&G);
	ft_lstadd_back(&a, tmp);
	ft_lstadd_front(&b, tmp2);
	tmp = ft_lstnew(&D);
	tmp2 = ft_lstnew(&H);
	printf("flag\n");
	ft_lstadd_back(&a, tmp);
	ft_lstadd_front(&b, tmp2);
	tmp = a;
	tmp2 = b;
	while(tmp || tmp2)
	{
		if (tmp)
		{
			i = *(int *)tmp->content;
			printf("a : %d    ",i);
			tmp = tmp->next;
		}
		else
			printf("         "); 
		if (tmp2)
		{
			j = *(int *)tmp2->content;
			printf("b : %d", j);
			tmp2 = tmp2->next;
		}
		printf("\n");
	}
	printf(".......\n");
	ft_rra(&a);
	tmp = a;
	tmp2 = b;
	while(tmp || tmp2)
	{
		if (tmp)
		{
			i = *(int *)tmp->content;
			printf("a : %d    ",i);
			tmp = tmp->next;
		}
		else
			printf("         "); 
		if (tmp2)
		{
			j = *(int *)tmp2->content;
			printf("b : %d", j);
			tmp2 = tmp2->next;
		}
		printf("\n");
	}
	printf("-----\n");
	ft_rrb(&b);
	tmp = a;
	tmp2 = b;
	while(tmp || tmp2)
	{
		if (tmp)
		{
			i = *(int *)tmp->content;
			printf("a : %d    ",i);
			tmp = tmp->next;
		}
		else
			printf("         "); 
		if (tmp2)
		{
			j = *(int *)tmp2->content;
			printf("b : %d", j);
			tmp2 = tmp2->next;
		}
		printf("\n");
	}
	printf(".......\n");
	ft_rrr(&a,&b);
	tmp = a;
	tmp2 = b;
	while(tmp || tmp2)
	{
		if (tmp)
		{
			i = *(int *)tmp->content;
			printf("a : %d    ",i);
			tmp = tmp->next;
		}
		else
			printf("         "); 
		if (tmp2)
		{
			j = *(int *)tmp2->content;
			printf("b : %d", j);
			tmp2 = tmp2->next;
		}
		printf("\n");
	}
	printf("/////\n");
	ft_pb(&b, &a);
	tmp = a;
	tmp2 = b;
	while(tmp || tmp2)
	{
		if (tmp)
		{
			i = *(int *)tmp->content;
			printf("a : %d    ",i);
			tmp = tmp->next;
		}
		else
			printf("         "); 
		if (tmp2)
		{
			j = *(int *)tmp2->content;
			printf("b : %d", j);
			tmp2 = tmp2->next;
		}
		printf("\n");
	}

	return (0);
}
