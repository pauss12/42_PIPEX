/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:54:29 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:54:47 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Calcula el signo del número basado en los caracteres de signo en la cadena.
 *
 * @param numminus: Contador de signos negativos encontrados.
 * @param str: La cadena de caracteres de la cual extraer el signo.
 * @param i: Índice actual en la cadena.
 * @return: El contador de signos negativos (0 o 1).
 * Actualiza el índice `i` para que apunte al siguiente carácter después del signo.
 */
static int	cal_sig(int numminus, char *str, int *i)
{
	if (str[*i] != '\0' && (str[*i] == '+' || str[*i] == '-'))
	{
		if (str[*i] == '-')
			numminus += 1;
		*i = *i + 1;
	}
	return (numminus);
}

/**
 * Convierte una cadena de caracteres a un número entero largo, teniendo en cuenta los signos.
 *
 * @param str: La cadena de caracteres que se convertirá.
 * @param state: Estado para indicar si el valor está fuera del rango de un entero (1 si fuera de rango, 0 si dentro del rango).
 * @return: El valor entero convertido.
 */
long	ft_atoi_changed(char *str, int *state)
{
	int					sig;
	unsigned long long	result;
	int					i;
	int					numminus;

	i = 0;
	result = 0;
	sig = 1;
	numminus = 0;
	while (str[i] == ' ')
		i++;
	if (cal_sig(numminus, str, &i))
		sig = -1;
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (result > ((long long int)INT_MAX + 1) && sig == -1)
			*state = 1;
		if (result > ((long long int)INT_MAX) && sig == 1)
			*state = 1;
	}
	return (result * sig);
}
