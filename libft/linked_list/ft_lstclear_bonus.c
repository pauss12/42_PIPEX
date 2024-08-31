/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:11:23 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:57:11 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Borra todos los nodos de una lista enlazada llamando a una función de
 * eliminación pasada como argumento.
 * Mientras la lista no esté vacía, guarda el siguiente nodo en una
 * variable temporal, llama a la función de eliminación para eliminar
 * el nodo actual, y luego actualiza el puntero a la lista al siguiente nodo.
 *
 * @param lst: Puntero a un puntero al primer nodo de la lista.
 * @param del: Función de eliminación a llamar para cada nodo de la lista.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (del == NULL || lst == NULL || *lst == NULL)
		return ;
	while (lst != NULL && *lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
