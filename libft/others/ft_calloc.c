/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:29:08 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/13 18:12:32 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Asigna memoria dinámicamente y la inicializa a cero.
 * Asigna memoria dinámicamente para el número de elementos multiplicado
 * por el tamaño de cada elemento.
 * Inicializa a cero el bloque de memoria asignado.
 * Retorna un puntero al bloque de memoria asignado.
 *
 * @param count: Número de elementos a asignar.
 * @param size: Tamaño de cada elemento.
 * @return: Puntero al bloque de memoria asignado, o nulo si la
 * asignación falló.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count == 0 || size == 0)
		return (NULL);
	if (count > SIZE_MAX / size)
		return (NULL);
	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
