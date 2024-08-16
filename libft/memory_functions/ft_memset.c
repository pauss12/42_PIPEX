/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:24:02 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:55:22 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	char	*p;

	p = (char *)ptr;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (ptr);
}
