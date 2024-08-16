/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:31:53 by pmendez-          #+#    #+#             */
/*   Updated: 2023/10/28 17:55:03 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printchar(int c)
{
	int	numchar;
	int	aux;

	numchar = 0;
	aux = write(1, &c, 1);
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	return (numchar);
}
