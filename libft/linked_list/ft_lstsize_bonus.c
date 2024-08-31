/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:32:17 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:58:18 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Calcula el tamaño de una lista enlazada, es decir, el número de nodos
 * en la lista.
 * Pasa al siguiente nodo y aumenta el contador en 1 mientras la lista
 * no esté vacía.
 * Cuando la lista esté vacía, retorna el contador, que es el tamaño de
 * la lista.
 *
 * @param lst: Puntero al primer nodo de la lista.
 * @return: El tamaño de la lista.
 */
int	ft_lstsize(t_list *lst)
{
	int	tam;

	tam = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		tam++;
	}
	return (tam);
}
