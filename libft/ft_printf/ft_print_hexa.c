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

/**
 * Imprime la representación hexadecimal de un número mayor o igual a 16.
 * Divide el número entre 16 para obtener el dígito más significativo y llama a
 * `ft_print_hexa` recursivamente. Luego imprime el dígito menos significativo.
 *
 * @param number: Número entero a convertir en hexadecimal.
 * @param type: Tipo de representación hexadecimal ('x' para minúsculas, 'X' para mayúsculas).
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
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

/**
 * Imprime la representación hexadecimal de un número menor a 16.
 * Convierte el número en un carácter hexadecimal (0-9, a-f, A-F) y lo imprime.
 *
 * @param number: Número entero a convertir en hexadecimal.
 * @param type: Tipo de representación hexadecimal ('x' para minúsculas, 'X' para mayúsculas).
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
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

/**
 * Imprime la representación hexadecimal de un número entero.
 * Llama a `numbers_more_sixteen` para números mayores o iguales a 16 y a
 * `numbers_below_sixteen` para números menores a 16.
 *
 * @param number: Número entero a convertir en hexadecimal.
 * @param type: Tipo de representación hexadecimal ('x' para minúsculas, 'X' para mayúsculas).
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
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
