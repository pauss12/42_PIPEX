/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:02:30 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 18:02:04 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Elimina caracteres específicos de los extremos de una cadena.
 * Crea una nueva cadena a partir de `s1`, eliminando los caracteres
 * que están en el conjunto `set` tanto al principio como al final de `s1`.
 *
 * @param s1: Cadena de entrada de la que se eliminarán los caracteres.
 * @param set: Conjunto de caracteres a eliminar de los extremos de `s1`.
 * @return Un puntero a la nueva cadena resultante. Retorna NULL si la reserva de memoria falla.
 */
char	*ft_strtrim(char *s1, char *set)
{
	char	*ptr1;
	char	*result;
	int		cont;
	int		j;

	ptr1 = (char *)s1;
	result = NULL;
	j = 0;
	if (s1 != 0)
	{
		cont = 0;
		j = ft_strlen(ptr1);
		while (ptr1[cont] != '\0' && ft_strchr(set, ptr1[cont]))
			cont++;
		while ((j > cont) && ft_strchr(set, ptr1[j - 1]))
			j--;
		result = malloc(sizeof(char) * (j - cont + 1));
		if (result == NULL)
			return (NULL);
		if (result)
			ft_strlcpy(result, &ptr1[cont], j - cont + 1);
	}
	return (result);
}
