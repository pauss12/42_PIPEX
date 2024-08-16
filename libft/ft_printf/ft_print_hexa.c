/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:31:30 by pmendez-          #+#    #+#             */
/*   Updated: 2023/10/28 17:57:29 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	numbers_more_sixteen(unsigned int number, char type)
{
	int		numchar;
	int		aux;

	numchar = 0;
	aux = 0;
	aux = ft_print_hexa(number / 16, type);
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	aux = ft_print_hexa(number % 16, type);
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	return (numchar);
}

static int	numbers_below_sixteen(unsigned int number, char type)
{
	int	numchar;
	int	aux;

	numchar = 0;
	aux = 0;
	if (number <= 9)
		numchar = numchar + ft_printchar(number + 48);
	else
	{
		if (type == 'x')
		{
			aux = ft_printchar(number - 10 + 'a');
			if (aux == -1)
				return (-1);
			numchar = numchar + aux;
		}
		else if (type == 'X')
		{
			aux = ft_printchar(number - 10 + 'A');
			if (aux == -1)
				return (-1);
			numchar = numchar + aux;
		}
	}
	return (numchar);
}

int	ft_print_hexa(unsigned int number, char type)
{
	int	numchar;
	int	aux;

	numchar = 0;
	aux = 0;
	if (number >= 16)
	{
		aux = numbers_more_sixteen(number, type);
		if (aux == -1)
			return (-1);
		numchar = numchar + aux;
	}
	else
	{
		aux = numbers_below_sixteen(number, type);
		if (aux == -1)
			return (-1);
		numchar = numchar + aux;
	}
	return (numchar);
}
