/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:25:14 by pmendez-          #+#    #+#             */
/*   Updated: 2023/10/28 17:54:20 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_typeof_data(char *input, va_list args)
{
	int	numchar;

	numchar = 0;
	if (*input == 'c')
	{
		numchar = numchar + ft_printchar(va_arg(args, int));
		if (numchar == -1)
			return (-1);
	}
	else if ((*input == 'd' || *input == 'i'))
		numchar = numchar + ft_print_integer(va_arg(args, int));
	else if (*input == 's')
		numchar = numchar + ft_printstr(va_arg(args, char *));
	else if (*input == 'p')
		numchar = numchar + ft_printpointer(va_arg(args, unsigned long long));
	else if (*input == '%')
		numchar = numchar + ft_printchar(*input);
	else if (*input == 'x' || *input == 'X')
		numchar = numchar + ft_print_hexa(va_arg(args, unsigned int), *input);
	else if (*input == 'u')
		numchar = numchar + ft_print_unsigned_int(va_arg(args, unsigned int));
	else
		return (0);
	return (numchar);
}

static int	check_once_encountered(char *input, va_list args)
{
	int		aux;

	aux = ft_typeof_data((char *)input, args);
	return (aux);
}

static int	go_through(const char *input, va_list args)
{
	int		numchar;
	int		aux;

	numchar = 0;
	aux = 0;
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			aux = check_once_encountered((char *)input, args);
			if (aux == -1)
				return (-1);
			numchar += aux;
		}
		else
		{
			aux = ft_printchar(*input);
			if (aux == -1)
				return (-1);
			numchar += aux;
		}
		input++;
	}
	return (numchar);
}

int	ft_printf(char const *input, ...)
{
	int		numchar;
	va_list	args;

	numchar = 0;
	va_start(args, input);
	numchar = numchar + go_through(input, args);
	va_end(args);
	return (numchar);
}
