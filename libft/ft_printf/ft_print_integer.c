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

/**
 * Imprime el número entero más negativo que puede representarse en un entero de 32 bits.
 * Maneja el caso especial para el menor valor posible, que es `-2147483648`, imprimiendo
 * el signo '-' seguido de la cadena "2147483648".
 *
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
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
/**
 * Imprime un número entero negativo.
 * Imprime el signo negativo seguido de la representación textual del número entero positivo.
 *
 * @param n: Número entero negativo a imprimir.
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
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

/**
 * Imprime un número entero positivo mayor de 9.
 * Divide el número en dígitos individuales y los imprime en orden.
 *
 * @param n: Número entero positivo a imprimir.
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
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

/**
 * Imprime un número entero.
 * Maneja casos especiales para el número entero más negativo, números negativos,
 * números de un solo dígito y números positivos mayores de 9.
 *
 * @param n: Número entero a imprimir.
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
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
