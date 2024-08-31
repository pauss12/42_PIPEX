/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:10:43 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 18:01:07 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Copiar una cadena en otra con tamaño limitado.
 * Copia hasta `dstsize - 1` caracteres de la cadena `src` en `dest`,
 * asegurándose de que el resultado esté null-terminado si `dstsize` es mayor que 0.
 *
 * @param dest: Cadena de destino donde se copiará la cadena `src`.
 * @param src: Cadena fuente que se copiará en `dest`.
 * @param dstsize: Tamaño del buffer `dest`, incluyendo el espacio para el carácter nulo.
 * @return La longitud total de la cadena `src`, lo que permite verificar si hubo truncamiento.
 */
size_t	ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	size_t	contador;
	size_t	tamsrc;

	contador = 0;
	if (dstsize == 0)
	{
		tamsrc = ft_strlen(src);
		return (tamsrc);
	}
	while (contador < dstsize - 1 && src[contador] != '\0')
	{
		dest[contador] = src[contador];
		contador++;
	}
	dest[contador] = '\0';
	tamsrc = 0;
	while (src[tamsrc] != '\0')
	{
		tamsrc++;
	}
	return (tamsrc);
}
