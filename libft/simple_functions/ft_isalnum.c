/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:16:45 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/12 16:52:38 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Verifica si un carácter dado es alfanumérico.
 * Si el carácter es una letra (mayúscula o minúscula) o un número, retorna 1.
 * Si el carácter no es una letra ni un número, retorna 0.
 *
 * @param c: El carácter a verificar.
 * @return: 1 si el carácter es alfanumérico, 0 en caso contrario.
 */
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
