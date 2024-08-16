/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:02:30 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 18:02:04 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	char	*ptr1;
	char	*result;
	int		cont;
	int		j;

	ptr1 = (char *)s1;
	result = NULL;
	j = 0;
	if (s1 != 0)
	{
		cont = 0;
		j = ft_strlen(ptr1);
		while (ptr1[cont] != '\0' && ft_strchr(set, ptr1[cont]))
			cont++;
		while ((j > cont) && ft_strchr(set, ptr1[j - 1]))
			j--;
		result = malloc(sizeof(char) * (j - cont + 1));
		if (result == NULL)
			return (NULL);
		if (result)
			ft_strlcpy(result, &ptr1[cont], j - cont + 1);
	}
	return (result);
}
