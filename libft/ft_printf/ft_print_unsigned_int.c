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

/**
 * Imprime un número entero sin signo mayor de 9.
 * Divide el número en dígitos individuales y los imprime en orden, comenzando por los dígitos más significativos.
 *
 * @param number: Número entero sin signo a imprimir.
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
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

/**
 * Imprime un número entero sin signo.
 * Maneja el caso especial para números de un solo dígito y usa `other_cases_unsigned` para números mayores de 9.
 *
 * @param number: Número entero sin signo a imprimir.
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
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
