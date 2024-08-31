/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:22:07 by pmendez-          #+#    #+#             */
/*   Updated: 2024/03/02 18:42:29 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Duplica una cadena de caracteres.
 * Calcula la longitud de la cadena de caracteres utilizando la función
 * ft_strlen.
 * Asigna memoria dinámicamente para una nueva cadena de caracteres de
 * la misma longitud que la cadena de caracteres original más 1
 * (para el carácter nulo al final de la cadena de caracteres).
 * Verifica si la asignación de memoria fue exitosa. Si no fue exitosa,
 * retorna nulo.
 * Copia los caracteres de la cadena de caracteres original a la nueva
 * cadena de caracteres.
 * Agrega un carácter nulo al final de la nueva cadena de caracteres.
 * Retorna la nueva cadena de caracteres.
 *
 * @param str: Cadena de caracteres a duplicar.
 * @return: Nueva cadena de caracteres duplicada de la cadena de
 * caracteres original, o nulo si la asignación de memoria falló.
 */
char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dest;
	int		contador;
	char	*str1;

	str1 = (char *)s1;
	len = 0;
	contador = 0;
	len = ft_strlen(s1);
	dest = (char *)ft_calloc((len + 1), sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (contador <= len)
	{
		dest[contador] = str1[contador];
		contador++;
	}
	return (dest);
}
