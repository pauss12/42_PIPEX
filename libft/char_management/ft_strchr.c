/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:03:30 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 18:00:24 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == (char)c)
			return ((char *)s + cont);
		cont++;
	}
	if ((char)c == '\0' && (char)s[cont] == '\0')
		return ((char *)s + cont);
	return (NULL);
}
