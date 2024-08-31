/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:15:15 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:58:59 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Imprime un número en hexadecimal cuando el número es menor o igual a 15.
 * Imprime caracteres individuales para valores en el rango de 0 a 9 y a-f.
 *
 * @param number: Número en el rango de 0 a 15 para imprimir en formato hexadecimal.
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
static int	print_below_sixteen(unsigned long long number)
{
	int	numchar;
	int	aux;

	numchar = 0;
	aux = 0;
	if (number <= 9)
	{
		aux = ft_printchar(number + 48);
		if (aux == -1)
			return (-1);
		numchar = numchar + aux;
	}
	else
	{
		aux = ft_printchar(number - 10 + 'a');
		if (aux == -1)
			return (-1);
		numchar = numchar + aux;
	}
	return (numchar);
}

/**
 * Imprime un número en formato hexadecimal usando recursión.
 * Divide el número en dígitos hexadecimales y llama a sí misma para imprimir los dígitos más significativos primero.
 *
 * @param number: Número en formato decimal que se imprimirá en formato hexadecimal.
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
int	ft_print_hexa_changed(unsigned long long number)
{
	int	numchar;

	numchar = 0;
	if (number > 15)
	{
		numchar = numchar + ft_print_hexa_changed(number / 16);
		numchar = numchar + ft_print_hexa_changed(number % 16);
	}
	else
	{
		numchar = print_below_sixteen(number);
	}
	return (numchar);
}

/**
 * Imprime un puntero en formato hexadecimal, precedido por "0x".
 * Llama a `ft_print_hexa_changed` para imprimir la representación hexadecimal del puntero.
 *
 * @param pointer: Valor del puntero que se imprimirá en formato hexadecimal.
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
int	ft_printpointer(unsigned long long pointer)
{
	int	numchar;
	int	aux;

	numchar = 0;
	aux = 0;
	aux = ft_printstr("0x");
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	numchar = numchar + ft_print_hexa_changed(pointer);
	return (numchar);
}
