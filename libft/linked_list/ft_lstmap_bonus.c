/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:52:11 by pmendez-          #+#    #+#             */
/*   Updated: 2024/02/03 17:57:55 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*content_temp;

	temp = NULL;
	new = NULL;
	if (f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		content_temp = f(lst->content);
		temp = ft_lstnew(content_temp);
		if (temp == NULL)
		{
			del(content_temp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
