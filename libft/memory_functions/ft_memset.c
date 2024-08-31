/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:24:02 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:55:22 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Escribe un valor dado en un bloque de memoria.
 * Escribe el valor en la posición del contador del bloque de memoria y
 * luego incrementa el contador.
 * Cuando el contador sea igual al tamaño, retorna el puntero al bloque
 * de memoria.
 *
 * @param str: Bloque de memoria en el que escribir.
 * @param c: Valor a escribir.
 * @param len: Tamaño del bloque de memoria.
 * @return: Puntero al bloque de memoria.
 */
void	*ft_memset(void *ptr, int c, size_t len)
{
	char	*p;

	p = (char *)ptr;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (ptr);
}
