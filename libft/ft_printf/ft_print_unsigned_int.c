/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:12:54 by pmendez-          #+#    #+#             */
/*   Updated: 2023/11/01 19:14:25 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	other_cases_unsigned(unsigned int number)
{
	unsigned int	numchar;
	unsigned int	aux;

	numchar = 0;
	aux = ft_print_unsigned_int(number / 10);
	if (aux == (unsigned int)-1)
		return (-1);
	numchar = numchar + aux;
	aux = 0;
	aux = ft_printchar(48 + (number % 10));
	if (aux == (unsigned int)-1)
		return (-1);
	numchar = numchar + aux;
	return (numchar);
}

int	ft_print_unsigned_int(unsigned int number)
{
	unsigned int	numchar;
	unsigned int	aux;

	numchar = 0;
	aux = 0;
	if (number > 0 && number <= 9)
	{
		aux = ft_printchar(number + '0');
		if (aux == (unsigned int)-1)
			return (-1);
		numchar = numchar + aux;
	}
	else
	{
		aux = other_cases_unsigned(number);
		if (aux == (unsigned int)-1)
			return (-1);
		numchar = numchar + aux;
	}
	return (numchar);
}
