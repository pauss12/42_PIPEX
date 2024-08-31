/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:25:09 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/12 16:55:04 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Verifica si un carácter dado es imprimible.
 * Si el valor del carácter está entre 32 y 126, retorna 1.
 * Si el valor del carácter no está entre 32 y 126, retorna 0.
 *
 * @param c: El carácter a verificar.
 * @return: 1 si el carácter es imprimible, 0 en caso contrario.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
