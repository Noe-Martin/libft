/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:25:30 by nmartin           #+#    #+#             */
/*   Updated: 2025/01/04 21:06:47 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gnl_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = s;
	i = 0;
	while (i < n)
		str[i++] = 0;
}

int	gnl_str_lst_len(t_list *lst)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (lst)
	{
		i = 0;
		str = lst->content;
		while (str[i] && str[i++] != '\n')
			len++;
		if (gnl_nl_chr(str, BUFFER_SIZE))
			return (++len);
		lst = lst->next;
	}
	return (len);
}

int	gnl_nl_chr(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (str[i] && i < len)
	{
		if (str[i++] == '\n')
			return (1);
	}
	return (0);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	total;

	total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	str = malloc(total);
	if (!str)
		return (NULL);
	gnl_bzero(str, total);
	return (str);
}

t_list	*gnl_lstnew(char *buffer)
{
	t_list	*new;
	char	*content;
	int		i;

	i = 0;
	new = malloc(sizeof(t_list));
	content = gnl_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!new || !content)
		return (free(new), NULL);
	while (buffer[i])
	{
		content[i] = buffer[i];
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	new->content = content;
	new->next = NULL;
	return (new);
}
