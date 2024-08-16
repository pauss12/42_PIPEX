/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:19:11 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:59:54 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <string.h>

static int	count_character(char *str, char c)
{
	int	cont;
	int	numstr;

	cont = 0;
	numstr = 0;
	while (str[cont] != '\0')
	{
		if (str[cont] != c)
		{
			numstr++;
			while (str[cont] != c && str[cont] != '\0')
				cont++;
		}
		else
			cont++;
	}
	return (numstr);
}

static char	*reserve_and_copy_str(char *str, char c, int *pos)
{
	char	*result;
	int		str_length;
	int		i;

	i = *pos;
	str_length = 0;
	result = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		str_length++;
		i++;
	}
	result = (char *)ft_calloc((str_length + 1), sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, str + *pos, str_length + 1);
	*pos += str_length;
	return (result);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	int		numstr;
	int		j;
	int		pos;

	if (s == NULL)
		return (NULL);
	j = 0;
	pos = 0;
	numstr = count_character((char *)s, c);
	result = (char **)ft_calloc((numstr + 1), sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (j < numstr && result != NULL)
	{
		while (s[pos] == c)
			pos++;
		result[j] = reserve_and_copy_str((char *)s, c, &pos);
		if (result[j] == NULL)
			return (NULL);
		j++;
	}
	return (result);
}
