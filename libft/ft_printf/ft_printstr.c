/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:32:22 by pmendez-          #+#    #+#             */
/*   Updated: 2023/11/01 19:15:33 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Imprime una cadena de caracteres en la salida estándar.
 * Si el puntero de la cadena es NULL, imprime "(null)".
 *
 * @param str: Puntero a la cadena de caracteres a imprimir.
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
int	ft_printstr(char *str)
{
	int	numchar;
	int	aux;
	int	i;

	numchar = 0;
	aux = 0;
	i = 0;
	if (str == NULL)
	{
		aux = write(1, "(null)", 6);
		if (aux == -1)
			return (-1);
		return (6);
	}
	aux = 0;
	while (str[i] != '\0')
	{
		aux = ft_printchar(str[i]);
		if (aux == -1)
			return (-1);
		numchar = numchar + aux;
		i++;
	}
	return (numchar);
}
