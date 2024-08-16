/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:24:59 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 18:01:22 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while (((s1[cont] != '\0') || (s2[cont] != '\0')) && (cont < n))
	{
		if (s1[cont] != s2[cont])
		{
			return ((unsigned char)s1[cont] - ((unsigned char)s2[cont]));
		}
		cont++;
	}
	return (0);
}
