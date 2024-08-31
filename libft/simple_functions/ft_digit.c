/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:23:35 by pmendez-          #+#    #+#             */
/*   Updated: 2024/03/02 18:44:17 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Verifica si un carácter dado es un dígito.
 * Si el carácter es un número del 0 al 9, retorna 1.
 * Si el carácter no es un número, retorna 0.
 *
 * @param c: El carácter a verificar.
 * @return: 1 si el carácter es un dígito, 0 en caso contrario.
 */
bool	ft_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}
