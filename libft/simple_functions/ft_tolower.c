/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:52:57 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/12 18:53:51 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Convierte un carácter a minúsculas si es una letra mayúscula.
 * Si el carácter es una letra mayúscula (su valor ASCII está entre 65 y 90),
 * suma 32 a su valor ASCII para convertirlo a minúsculas.
 * Retorna el carácter.
 *
 * @param c: Carácter a convertir a minúsculas.
 * @return: Carácter convertido a minúsculas, o el mismo carácter si no
 * era una letra mayúscula.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
