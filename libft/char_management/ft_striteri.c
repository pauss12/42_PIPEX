/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:26:55 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/18 16:47:56 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Aplica una función a cada carácter de una cadena con su índice.
 * Itera sobre la cadena `s`, aplicando la función `f` a cada carácter
 * junto con su índice dentro de la cadena.
 *
 * @param s: Cadena a la que se le aplicará la función.
 * @param f: Función a aplicar a cada carácter de la cadena,
 * que toma el índice del carácter y un puntero a este.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		f(cont, &s[cont]);
		cont++;
	}
}
