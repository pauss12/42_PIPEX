/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:40:16 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 18:01:37 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Busca una subcadena en una cadena limitada por un tamaño.
 * Busca la primera aparición de la subcadena `needle` en la cadena `haystack`,
 * pero solo dentro de los primeros `len` caracteres de `haystack`.
 *
 * @param haystack: Cadena en la que se realiza la búsqueda.
 * @param needle: Subcadena que se busca en `haystack`.
 * @param len: Número máximo de caracteres de `haystack` a examinar.
 * @return Un puntero al comienzo de la primera aparición de `needle` en `haystack`,
 * o NULL si `needle` no se encuentra en los primeros `len` caracteres.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cont1;
	size_t	cont2;
	size_t	cont;

	cont2 = 0;
	cont = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[cont2] != '\0' && cont2 < len)
	{
		cont = cont2;
		cont1 = 0;
		while (haystack[cont] == needle[cont1] && (cont2 + cont1 < len))
		{
			if (needle[cont1 + 1] == '\0')
				return ((char *)&haystack[cont2]);
			cont++;
			cont1++;
		}
		cont2++;
	}
	return (NULL);
}
