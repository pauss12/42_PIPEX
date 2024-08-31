/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:56:17 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/16 20:05:08 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Calcula la longitud de una cadena de caracteres.
 * Mientras el carácter en la posición del primer contador de la cadena
 * de caracteres no sea el carácter nulo, incrementa el segundo contador
 * y el primer contador.
 * Retorna el segundo contador, que representa la longitud de la cadena
 * de caracteres.
 *
 * @param str: Cadena de caracteres cuya longitud calcular.
 * @return: Longitud de la cadena de caracteres.
 */
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
