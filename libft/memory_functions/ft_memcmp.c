/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:59:44 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:55:54 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cont;
	char	*str1;
	char	*str2;

	cont = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (cont < n)
	{
		if (str1[cont] != str2[cont])
			return ((unsigned char)str1[cont] - (unsigned char)str2[cont]);
		cont++;
	}
	return (0);
}
