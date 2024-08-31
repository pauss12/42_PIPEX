/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:02:00 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:56:50 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Añade un nuevo nodo a la cola de una lista enlazada.
 * Si la lista está vacía, establece el nuevo nodo como el primer nodo
 * de la lista.
 * Si la lista no está vacía, establece el campo `next` del último nodo
 * para apuntar al nuevo nodo.
 *
 * @param lst: Puntero a un puntero al primer nodo de la lista.
 * @param new: Puntero al nuevo nodo a añadir a la lista.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
	}
}
