/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:33:01 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:56:18 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Copia un bloque de memoria de una ubicación a otra, manejando
 * correctamente los casos en los que la ubicación de origen y destino
 * se superponen.
 * Si la ubicación de origen es menor que la ubicación de destino,
 * copia los datos desde la ubicación de origen hacia atrás hasta la
 * ubicación de destino.
 * Si la ubicación de origen es mayor que o igual a la ubicación
 * de destino, copia los datos desde la ubicación de origen hacia
 * adelante hasta la ubicación de destino.
 * Cuando se hayan copiado todos los datos, retorna el puntero a
 * la ubicación de destino.
 *
 * @param dst: Puntero a la ubicación de destino.
 * @param src: Puntero a la ubicación de origen.
 * @param len: Tamaño del bloque de memoria a copiar.
 * @return: Puntero a la ubicación de destino.
 */
void	*ft_memmove(void *dest, void *src, size_t len)
{
	char		*dest2;
	char		*src2;

	dest2 = (char *)dest;
	src2 = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
	{
		return (ft_memcpy(dest, src, len));
	}
	else
	{
		while (len > 0)
		{
			dest2[len - 1] = src2[len - 1];
			len--;
		}
	}
	return (dest);
}
