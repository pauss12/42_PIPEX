/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:49:08 by pmendez-          #+#    #+#             */
/*   Updated: 2023/09/18 18:30:04 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Imprime un número entero en un descriptor de archivo.
 * Escribe la representación textual del número `n` en el descriptor de archivo `fd`.
 * Maneja el caso especial del menor valor posible para un entero (`-2147483648`),
 * así como números negativos y positivos.
 *
 * @param n: Número entero que se va a imprimir.
 * @param fd: Descriptor de archivo en el que se imprimirá el número.
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n <= 9 && n >= 0)
		ft_putchar_fd(n + '0', fd);
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
