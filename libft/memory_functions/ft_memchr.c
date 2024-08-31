/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:51:25 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:55:36 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Busca un carácter específico en una cadena de caracteres.
 * Compara el carácter en la posición del contador con el carácter buscado.
 * Si son iguales, retorna un puntero al carácter.
 * Si el carácter buscado no se encuentra en la cadena de caracteres dentro
 * del tamaño especificado, retorna nulo.
 *
 * @param str: Cadena de caracteres en la que buscar.
 * @param c: Carácter a buscar.
 * @param n: Número máximo de bytes a considerar en la cadena de caracteres.
 * @return: Un puntero al primer carácter encontrado en la cadena de
 * caracteres, o nulo si el carácter no se encuentra.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			cont;

	ptr = (unsigned char *)s;
	cont = 0;
	while (cont < n)
	{
		if (ptr[cont] == (unsigned char)c)
			return (ptr + cont);
		cont++;
	}
	return (NULL);
}
