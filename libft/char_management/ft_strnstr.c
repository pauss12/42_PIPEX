/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:40:16 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 18:01:37 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cont1;
	size_t	cont2;
	size_t	cont;

	cont2 = 0;
	cont = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[cont2] != '\0' && cont2 < len)
	{
		cont = cont2;
		cont1 = 0;
		while (haystack[cont] == needle[cont1] && (cont2 + cont1 < len))
		{
			if (needle[cont1 + 1] == '\0')
				return ((char *)&haystack[cont2]);
			cont++;
			cont1++;
		}
		cont2++;
	}
	return (NULL);
}
