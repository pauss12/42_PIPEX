/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:13:49 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:57:01 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Añade un nuevo nodo al principio de una lista enlazada.
 * Establece el campo `next` del nuevo nodo para apuntar al primer nodo
 * de la lista.
 * Establece el primer nodo de la lista como el nuevo nodo.
 *
 * @param lst: Puntero a un puntero al primer nodo de la lista.
 * @param new: Puntero al nuevo nodo a añadir al principio de la lista.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == 0 || new == 0)
		return;
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}
