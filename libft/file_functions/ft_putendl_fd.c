/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:52:00 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/18 18:29:27 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Escribe una cadena de caracteres seguida de un salto de línea en un
 * descriptor de archivo especificado.
 * Primero llama a la función ft_putstr_fd para escribir la cadena
 * de caracteres.
 * Luego llama a la función ft_putchar_fd para escribir un salto de línea.
 *
 * @param s: La cadena de caracteres a escribir.
 * @param fd: El descriptor de archivo donde escribir la cadena de caracteres
 * y el salto de línea.
 */
void	ft_putendl_fd(char *s, int fd)
{
	char	*str;

	if (!s)
		return ;
	str = ft_strjoin(s, "\n");
	ft_putstr_fd(str, fd);
	free(str);
}
