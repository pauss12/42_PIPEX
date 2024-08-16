/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:22:07 by pmendez-          #+#    #+#             */
/*   Updated: 2024/03/02 18:42:29 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dest;
	int		contador;
	char	*str1;

	str1 = (char *)s1;
	len = 0;
	contador = 0;
	while (str1[len] != '\0')
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (contador <= len)
	{
		dest[contador] = str1[contador];
		contador++;
	}
	return (dest);
}
