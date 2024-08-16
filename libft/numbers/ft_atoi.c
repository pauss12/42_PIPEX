/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:54:29 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:54:47 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	cal_sig(int numminus, char *str, int *i)
{
	if (str[*i] != '\0' && (str[*i] == '+' || str[*i] == '-'))
	{
		if (str[*i] == '-')
			numminus += 1;
		*i = *i + 1;
	}
	return (numminus);
}

long	ft_atoi_changed(char *str, int *state)
{
	int					sig;
	unsigned long long	result;
	int					i;
	int					numminus;

	i = 0;
	result = 0;
	sig = 1;
	numminus = 0;
	while (str[i] == ' ')
		i++;
	if (cal_sig(numminus, str, &i))
		sig = -1;
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (result > ((long long int)INT_MAX + 1) && sig == -1)
			*state = 1;
		if (result > ((long long int)INT_MAX) && sig == 1)
			*state = 1;
	}
	return (result * sig);
}
