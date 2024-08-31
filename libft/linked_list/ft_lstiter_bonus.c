/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:46:57 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:57:32 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Aplica una función dada a cada elemento de una lista enlazada.
 * Mientras la lista no esté vacía, aplica la función al contenido del
 * nodo actual y luego pasa al siguiente nodo.
 *
 * @param lst: Puntero al primer nodo de la lista.
 * @param f: Función a aplicar a cada elemento de la lista.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*aux;

	aux = lst;
	while (aux != NULL)
	{
		f(aux->content);
		aux = aux->next;
	}
}
