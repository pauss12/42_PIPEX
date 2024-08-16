/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:37:57 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 18:01:50 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	cont;

	cont = ft_strlen(s);
	while (cont >= 0)
	{
		if ((char)s[cont] == (char)c)
		{
			return ((char *)s + cont);
		}
		cont--;
	}
	return (NULL);
}
