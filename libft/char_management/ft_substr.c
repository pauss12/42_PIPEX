/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:59:46 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/23 19:11:14 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Crea una subcadena de una cadena dada.
 * Extrae una subcadena de `s` comenzando en el índice `start` y con una longitud `len`.
 * Si `start` está fuera del rango de la cadena o si la longitud `len` excede el final
 * de la cadena, ajusta `len` para que no se salga del rango.
 *
 * @param s: Cadena de la que se extraerá la subcadena.
 * @param start: Índice de inicio para la subcadena.
 * @param len: Longitud deseada de la subcadena.
 * @return Un puntero a la nueva subcadena creada. Retorna NULL si la reserva de memoria falla.
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substring;

	if (s == NULL)
		return (NULL);
	if (start > ((size_t)ft_strlen(s)))
		start = ((size_t)ft_strlen(s));
	if (len > ((size_t)ft_strlen(s)) - start)
		len = ((size_t)ft_strlen(s)) - start;
	substring = (char *)malloc(sizeof(*s) * (len + 1));
	if (substring == NULL)
		return (NULL);
	ft_strlcpy(substring, (char *)(s + start), len + 1);
	return (substring);
}
