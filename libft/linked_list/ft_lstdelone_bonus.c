/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:41:54 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:57:22 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Elimina un solo nodo de una lista enlazada.
 * Llama a la función de eliminación para el contenido del nodo.
 * Libera la memoria asignada al nodo.
 *
 * @param lst: Puntero al nodo de la lista a eliminar.
 * @param del: Función de eliminación a llamar para el contenido del nodo.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
