/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:00:41 by nmartin           #+#    #+#             */
/*   Updated: 2025/01/05 12:43:54 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cpy_lst_to_line(t_list *first)
{
	int		i;
	int		y;
	char	*str;
	char	*line;
	t_list	*temp;

	line = gnl_calloc(sizeof(char), gnl_str_lst_len(first) + 1);
	if (!line)
		return (NULL);
	y = 0;
	while (first && !gnl_nl_chr(line, BUFFER_SIZE))
	{
		i = 0;
		str = first->content;
		temp = first->next;
		while (str[i] && str[i] != '\n')
			line[y++] = str[i++];
		if (gnl_nl_chr(str, BUFFER_SIZE))
			line[y] = '\n';
		free(first->content);
		free(first);
		first = temp;
	}
	return (line);
}

void	keep_line(char *buffer, int *free_buf)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (buffer[i])
		i++;
	if ((!gnl_nl_chr(buffer, BUFFER_SIZE - 1) && !buffer[BUFFER_SIZE - 1]
			&& buffer[0] != '\n') || (buffer[0] == '\n' && buffer[1] == 0))
	{
		*free_buf = 1;
		return ;
	}
	if (gnl_nl_chr(buffer, BUFFER_SIZE))
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		i++;
		while (buffer[i])
			buffer[y++] = buffer[i++];
	}
	while (buffer[y])
			buffer[y++] = 0;
}

t_list	*read_file(int fd, char *buffer, int *free_buf)
{
	t_list		*first;
	t_list		*lst;

	if (buffer[0] == 0)
	{
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (*free_buf = 1, NULL);
	}
	first = gnl_lstnew(buffer);
	if (!first)
		return (*free_buf = 1, NULL);
	lst = first;
	while (!gnl_nl_chr(lst->content, BUFFER_SIZE))
	{
		gnl_bzero(buffer, BUFFER_SIZE + 1);
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (*free_buf = 1, first);
		lst->next = gnl_lstnew(buffer);
		lst = lst->next;
	}
	return (keep_line(buffer, free_buf), first);
}

char	*get_next_line(int fd)
{
	t_list		*first;
	static char	buffer[BUFFER_SIZE + 1];
	int			free_buf;

	free_buf = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	first = read_file(fd, buffer, &free_buf);
	if (free_buf)
		gnl_bzero(buffer, BUFFER_SIZE + 1);
	if (!first || !first->content)
		return (free(first), NULL);
	return (cpy_lst_to_line(first));
}
