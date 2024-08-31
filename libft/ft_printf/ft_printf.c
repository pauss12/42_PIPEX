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

/**
 * Imprime diferentes tipos de datos basados en el especificador de formato en la cadena de entrada.
 * Esta función utiliza `va_arg` para extraer los argumentos de la lista de argumentos variable
 * y luego llama a las funciones correspondientes para imprimir el tipo de dato adecuado.
 *
 * @param input: Especificador de formato que indica el tipo de dato a imprimir.
 * @param args: Lista de argumentos variable de la función `ft_printf`.
 * @return El número total de caracteres impresos para el formato especificado, o -1 en caso de error.
 */
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

/**
 * Llama a `ft_typeof_data` para procesar el especificador de formato encontrado en la cadena de entrada.
 *
 * @param input: Especificador de formato que indica el tipo de dato a imprimir.
 * @param args: Lista de argumentos variable de la función `ft_printf`.
 * @return El número total de caracteres impresos para el formato especificado, o -1 en caso de error.
 */
static int	check_once_encountered(char *input, va_list args)
{
	int		aux;

	aux = ft_typeof_data((char *)input, args);
	return (aux);
}

/**
 * Recorre la cadena de entrada y maneja los especificadores de formato y caracteres normales.
 * Imprime caracteres y valores formateados utilizando `ft_typeof_data` para los especificadores de formato.
 *
 * @param input: Cadena de entrada que contiene los especificadores de formato y texto.
 * @param args: Lista de argumentos variable de la función `ft_printf`.
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
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

/**
 * Función principal de formato e impresión. Maneja el formateo y la impresión de texto basado en
 * una cadena de entrada con especificadores de formato, utilizando una lista de argumentos variable.
 *
 * @param input: Cadena de entrada que contiene los especificadores de formato y texto.
 * @param ...: Lista variable de argumentos para los especificadores de formato.
 * @return El número total de caracteres impresos, o -1 en caso de error.
 */
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
