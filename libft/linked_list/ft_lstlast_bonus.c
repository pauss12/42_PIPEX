/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:52:46 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:57:42 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Devuelve el último nodo de una lista enlazada.
 * Mientras haya un siguiente nodo en la lista, avanza al siguiente nodo.
 * Cuando ya no haya un siguiente nodo, retorna el nodo actual, que es el
 * último nodo de la lista.
 *
 * @param lst: Puntero al primer nodo de la lista.
 * @return: El último nodo de la lista.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
