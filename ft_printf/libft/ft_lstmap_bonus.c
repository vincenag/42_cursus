/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:34:49 by agvincen          #+#    #+#             */
/*   Updated: 2023/05/31 16:25:17 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*aux;

	if (lst && f && del)
	{
		new_list = ft_lstnew(f(lst->content));
		aux = new_list;
		if (!new_list)
			return (0);
		lst = lst->next;
		while (lst)
		{
			new_list->next = ft_lstnew(f(lst->content));
			if (!new_list->next)
			{
				ft_lstclear(&aux, del);
				return (0);
			}
			new_list = new_list->next;
			lst = lst->next;
		}
		new_list->next = 0;
		return (aux);
	}
	return (0);
}
