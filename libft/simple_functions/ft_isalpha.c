/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:15:52 by pmendez-          #+#    #+#             */
/*   Updated: 2024/03/02 18:43:30 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Verifica si un carácter dado es una letra.
 * Si el carácter es una letra (mayúscula o minúscula), retorna 1.
 * Si el carácter no es una letra, retorna 0.
 *
 * @param c: El carácter a verificar.
 * @return: 1 si el carácter es una letra, 0 en caso contrario.
 */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
