/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:31:53 by pmendez-          #+#    #+#             */
/*   Updated: 2023/10/28 17:55:03 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Imprime un solo carácter en la salida estándar.
 * Utiliza la función `write` para enviar el carácter al descriptor de archivo 1,
 * que corresponde a la salida estándar (stdout).
 *
 * @param c: Carácter a imprimir, representado como un valor entero.
 *           La conversión de tipo asegura que se interprete correctamente como un carácter.
 * @return El número total de caracteres impresos (siempre 1), o -1 en caso de error.
 */
int	ft_printchar(int c)
{
	int	numchar;
	int	aux;

	numchar = 0;
	aux = write(1, &c, 1);
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	return (numchar);
}
