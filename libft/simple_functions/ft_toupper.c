/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:26:16 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/12 19:00:17 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Convierte un carácter a mayúsculas si es una letra minúscula.
 * Si el carácter es una letra minúscula (su valor ASCII está entre 97 y 122),
 * resta 32 a su valor ASCII para convertirlo a mayúsculas.
 * Retorna el carácter.
 *
 * @param c: Carácter a convertir a mayúsculas.
 * @return: Carácter convertido a mayúsculas, o el mismo carácter si no era
 * una letra minúscula.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
