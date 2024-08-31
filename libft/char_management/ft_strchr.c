/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:03:30 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 18:00:24 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Busca la primera aparición de un carácter en una cadena.
 * Recorre la cadena `s` buscando la primera aparición del carácter `c`.
 * Si encuentra el carácter, devuelve un puntero a la posición en la cadena.
 * Si el carácter `c` es el carácter nulo ('\0'), devuelve un puntero al final de la cadena.
 *
 * @param s: Cadena en la que se busca el carácter.
 * @param c: Carácter a buscar en la cadena.
 * @return Un puntero a la primera aparición del carácter `c` en la cadena `s`.
 * Retorna NULL si el carácter no se encuentra.
 */
char	*ft_strchr(char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == (char)c)
			return ((char *)s + cont);
		cont++;
	}
	if ((char)c == '\0' && (char)s[cont] == '\0')
		return ((char *)s + cont);
	return (NULL);
}
