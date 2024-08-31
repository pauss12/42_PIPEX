/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:37:57 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 18:01:50 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Busca la última aparición de un carácter en una cadena.
 * Recorre la cadena `s` desde el final hacia el principio para encontrar
 * la última ocurrencia del carácter `c`.
 *
 * @param s: Cadena en la que se busca el carácter.
 * @param c: Carácter a buscar en la cadena.
 * @return Un puntero a la última aparición del carácter `c` en la cadena `s`,
 * o NULL si el carácter no se encuentra.
 */
char	*ft_strrchr(const char *s, int c)
{
	int	cont;

	cont = ft_strlen(s);
	while (cont >= 0)
	{
		if ((char)s[cont] == (char)c)
		{
			return ((char *)s + cont);
		}
		cont--;
	}
	return (NULL);
}
