/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:20:11 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/23 17:06:01 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Concatenar dos cadenas con tamaño limitado.
 * Agrega la cadena `src` al final de la cadena `dest`, asegurándose de no
 * exceder el tamaño total de `dstsize`, incluyendo el carácter nulo.
 * Si `dstsize` es menor que la longitud de `dest`, no se concatena nada.
 *
 * @param dest: Cadena de destino, donde se añadirá la cadena `src`.
 * @param src: Cadena fuente que se añadirá al final de `dest`.
 * @param dstsize: Tamaño total del buffer `dest`, incluyendo el espacio para el carácter nulo.
 * @return La longitud total que habría tenido la cadena si no hubiese habido limitación por `dstsize`.
 */
size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < dstsize)
		i++;
	while (src[j] && (i + j + 1) < dstsize)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dest[i + j] = '\0';
	return (ft_strlen(src) + i);
}
