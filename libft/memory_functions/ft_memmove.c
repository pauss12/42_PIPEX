/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:33:01 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:56:18 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, void *src, size_t len)
{
	char		*dest2;
	char		*src2;

	dest2 = (char *)dest;
	src2 = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
	{
		return (ft_memcpy(dest, src, len));
	}
	else
	{
		while (len > 0)
		{
			dest2[len - 1] = src2[len - 1];
			len--;
		}
	}
	return (dest);
}
