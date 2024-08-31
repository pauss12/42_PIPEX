/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:48:15 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/18 16:48:52 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Escribe una cadena de caracteres en un descriptor de archivo especificado.
 * Utiliza la función write del sistema operativo para escribir la cadena
 * de caracteres.
 * La longitud de la cadena de caracteres se obtiene con
 * la función ft_strlen.
 *
 * @param s:  La cadena de caracteres a escribir.
 * @param fd: El descriptor de archivo donde escribir la cadena de caracteres.
 */
void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}
