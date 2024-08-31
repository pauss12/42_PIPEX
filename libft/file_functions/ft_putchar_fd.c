/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:42:52 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/18 16:43:42 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Escribe un solo carácter en un descriptor de archivo especificado.
 * Utiliza la función write del sistema operativo para escribir el carácter.
 *
 * @param c: El carácter a escribir.
 * @param  fd: El descriptor de archivo donde escribir el carácter.
 */
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
