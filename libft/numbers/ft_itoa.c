/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:34:30 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/25 18:45:21 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_numcif(int n)
{
	long int	nb;
	int			numcif;

	nb = n;
	numcif = 0;
	if (nb < 0)
	{
		nb = -nb;
		numcif++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		numcif++;
	}
	return (numcif);
}

static char	*ft_reserve(char *string, int numcif, long int nb)
{
	if (nb == 0)
	{
		string = ft_calloc(2, sizeof(char));
		if (string == NULL)
			return (0);
	}
	else
	{
		string = ft_calloc(numcif + 1, sizeof(char));
		if (string == NULL)
			return (0);
	}
	return (string);
}

char	*ft_itoa(int n)
{
	char		*string;
	int			numcif;
	long int	nb;

	nb = n;
	string = NULL;
	numcif = ft_numcif(nb);
	string = ft_reserve(string, numcif, nb);
	if (string == NULL)
		return (0);
	string[numcif--] = 0;
	if (nb == 0)
		string[0] = '0';
	if (nb < 0)
	{
		string[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		string[numcif--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (string);
}
