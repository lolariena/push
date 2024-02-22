//A SUPPRIMER !!!!!

#include <stdio.h>
#include "../includes/push_swap.h"

static int ft_test_minmax(int n, char c, int sign)//A AJOUTER
{
    if (n > 214748364)
        return (1);
    if (n == 214748364)
    {
        if((c > '7' && sign > 0) || (c > '8' && sign < 0))
			return (1);
    }
    return (0);
}

int	ft_atoi_with_error(const char *nptr)//ajouter check int min & max //cest ici que ca merdouille
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
		if (ft_test_minmax(n, nptr[i], sign))//CHANGEMENT ICI
			return (0);
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	if (nptr[i] && !ft_isdigit(nptr[i]))
		return (0);
	return (n * sign);
}

int main (int ac, char **av)
{
    int a;
    int i;

    i = 1;
    while (i < ac)
    {
        a = ft_atoi_with_error(av[i]);
        printf("%d\n",a);
        i++;
    }
    return (0);
}