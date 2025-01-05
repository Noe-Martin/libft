/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:38:02 by nmartin           #+#    #+#             */
/*   Updated: 2024/11/22 16:49:11 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*cleanlst(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		del(lst->content);
		free(lst);
		lst = temp;
	}
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*result;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	current = ft_lstnew(f(lst->content));
	if (!current)
		return (NULL);
	result = current;
	while (lst->next)
	{
		lst = lst->next;
		temp = ft_lstnew(f(lst->content));
		if (!temp)
			return (cleanlst(result, del));
		current->next = temp;
		current = current->next;
	}
	return (result);
}
