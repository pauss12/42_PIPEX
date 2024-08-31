/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:12:58 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 18:00:45 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Une dos cadenas en una nueva cadena.
 * Reserva memoria y concatena las cadenas `s1` y `s2`, creando una nueva cadena
 * que contiene `s1` seguido de `s2`.
 *
 * @param s1: Primera cadena.
 * @param s2: Segunda cadena.
 * @return Un puntero a la nueva cadena resultante de la concatenación de `s1` y `s2`.
 * Retorna NULL si la reserva de memoria falla.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ptr1;
	char	*ptr2;
	size_t	i;
	size_t	j;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	i = 0;
	j = 0;
	str = malloc(((ft_strlen(ptr1) + ft_strlen(ptr2)) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
