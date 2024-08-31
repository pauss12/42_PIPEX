/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:32:33 by pmendez-          #+#    #+#             */
/*   Updated: 2024/03/02 18:42:08 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Escribe ceros en un bloque de memoria.
 * Llama a la función ft_memset con el puntero a un bloque de memoria,
 * el valor 0 y el tamaño como argumentos.
 *
 * @param str: Bloque de memoria en el que escribir ceros.
 * @param n: Tamaño del bloque de memoria.
 */
void	ft_bzero(void *s, int size)
{
	ft_memset(s, 0, size);
}
