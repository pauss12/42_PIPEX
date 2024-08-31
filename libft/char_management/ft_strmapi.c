/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:46:08 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/18 18:28:35 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Aplica una función a cada carácter de una cadena y crea una nueva cadena.
 * Recorre la cadena `s`, aplicando la función `f` a cada carácter junto con su índice,
 * y almacena el resultado en una nueva cadena.
 *
 * @param s: Cadena de entrada a la que se le aplicará la función.
 * @param f: Función que toma el índice del carácter y el carácter en sí,
 * y devuelve un nuevo carácter.
 * @return Un puntero a la nueva cadena creada. Retorna NULL si la reserva de memoria falla.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)ft_calloc(ft_strlen((char *)s) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
