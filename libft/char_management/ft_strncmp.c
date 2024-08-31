/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:24:59 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 18:01:22 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Compara dos cadenas hasta un número limitado de caracteres.
 * Compara las cadenas `s1` y `s2` hasta un máximo de `n` caracteres o
 * hasta encontrar una diferencia. La comparación se realiza carácter a carácter.
 *
 * @param s1: Primera cadena a comparar.
 * @param s2: Segunda cadena a comparar.
 * @param n: Número máximo de caracteres a comparar.
 * @return Un valor entero:
 * - 0 si las cadenas son iguales hasta `n` caracteres.
 * - Un valor positivo si `s1` es mayor que `s2`.
 * - Un valor negativo si `s1` es menor que `s2`.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while (((s1[cont] != '\0') || (s2[cont] != '\0')) && (cont < n))
	{
		if (s1[cont] != s2[cont])
			return ((unsigned char)s1[cont] - ((unsigned char)s2[cont]));
		cont++;
	}
	return (0);
}
