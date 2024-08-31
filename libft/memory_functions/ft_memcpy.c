/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:45:12 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:56:05 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Copia un bloque de memoria de una ubicación a otra.
 * Copia el byte en la posición del contador de la ubicación de origen a
 * la ubicación de destino y luego incrementa el contador.
 * Cuando el contador sea igual al tamaño, retorna el puntero a la
 * ubicación de destino.
 *
 * @param dst: Puntero a la ubicación de destino.
 * @param src: Puntero a la ubicación de origen.
 * @param n: Tamaño del bloque de memoria a copiar.
 * @return: Puntero a la ubicación de destino.
 */
void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	contador;
	char	*dest;
	char	*src;

	dest = (char *)s1;
	src = (char *)s2;
	contador = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (contador < n)
	{
		dest[contador] = src[contador];
		contador++;
	}
	return (dest);
}
