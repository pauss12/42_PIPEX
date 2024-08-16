/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:51:25 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:55:36 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			cont;

	ptr = (unsigned char *)s;
	cont = 0;
	while (cont < n)
	{
		if (ptr[cont] == (unsigned char)c)
			return (ptr + cont);
		cont++;
	}
	return (NULL);
}
