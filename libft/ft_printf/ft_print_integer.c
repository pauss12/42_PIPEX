/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:15:40 by pmendez-          #+#    #+#             */
/*   Updated: 2023/10/28 17:50:09 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	min_negative(void)
{
	int	numchar;
	int	aux;

	numchar = 0;
	aux = ft_printchar('-');
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	aux = 0;
	aux = ft_printstr("2147483648");
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	return (numchar);
}

static int	negative_numbers(int n)
{
	int	aux;
	int	numchar;

	aux = 0;
	numchar = 0;
	aux = ft_printchar('-');
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	aux = 0;
	aux = ft_print_integer(n);
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	return (numchar);
}

static int	other_cases(int n)
{
	int	aux;
	int	numchar;

	aux = 0;
	numchar = 0;
	aux = ft_print_integer(n / 10);
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	aux = 0;
	aux = ft_printchar(48 + (n % 10));
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	return (numchar);
}

int	ft_print_integer(int n)
{
	int	numchar;
	int	aux;

	numchar = 0;
	aux = 0;
	if (n == -2147483648)
	{
		n = -n;
		numchar += min_negative();
	}
	else if (n < 0)
	{
		n = -n;
		numchar += negative_numbers(n);
	}
	else if (n >= 0 && n <= 9)
	{
		aux = ft_printchar(n + '0');
		if (aux == -1)
			return (-1);
		numchar = numchar + aux;
	}
	else
		numchar += other_cases(n);
	return (numchar);
}
