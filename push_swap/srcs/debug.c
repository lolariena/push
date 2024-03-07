//FICHIER A SUPPRIMER !!!!!

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

int	ft_atoi_with_error(const char *nptr)
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

int	ft_check_error_atoi(const char *nptr)
{
	int	i;
	int nb_nondigit;

	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	nb_nondigit = i;
	while (ft_isdigit(nptr[i]))
		i++;
	if ((nptr[i] && !ft_isdigit(nptr[i])) || ((i - nb_nondigit) >= 10))//CHANGEMENTS ICI & DEDANS
	{
		if (!nptr[i] && ((i - nb_nondigit) == 10))
		{
			if (nptr[0] == '-' && nptr[i - 1] <= '8')
				return (0);
			if ((nptr[0] == '+' || ft_isdigit(nptr[0])) && nptr[i - 1] < '8')
				return (0);
		}
		return (1);
	}
	return (0);
}

int main (int ac, char **av)
{
    int a;
    int i;

    i = 1;
    while (i < ac)
    {
        a = ft_check_error_atoi(av[i]);
        printf("%d\n",a);
        i++;
    }
    return (0);
}