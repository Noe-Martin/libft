/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:04:52 by nmartin           #+#    #+#             */
/*   Updated: 2025/01/02 15:26:13 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printer(char *str, int fd)
{
	if (!str)
	{
		ft_putchar_fd('\0', fd);
		return (1);
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

int	print_result(t_list *lst, int fd)
{
	int		len;
	char	*str;

	len = 0;
	while (lst)
	{
		str = (char *)(lst->content);
		len += printer(str, fd);
		lst = lst->next;
	}
	return (len);
}

int	print_txt(const char *str, t_list **rlst)
{
	int		y;
	int		x;
	char	*txt;

	y = 0;
	x = 0;
	while (str[y] && str[y] != '%')
		y++;
	txt = malloc(sizeof(char) * (y + 1));
	if (!txt)
	{
		str_error(rlst);
		return (0);
	}
	while (x < y)
	{
		txt[x] = str[x];
		x++;
	}
	txt[x] = '\0';
	(*rlst)->content = txt;
	return (y);
}

void	check_char(const char *str, va_list lst, t_list **rlst)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			i += print_txt(&str[i], rlst);
		else
			i += ft_printf_conv(&str[i], lst, rlst);
		if (!(*rlst) || !str[i])
			return ;
		(*rlst)->next = ft_lstnew("");
		if (!(*rlst)->next)
		{
			str_error(&((*rlst)->next));
			return ;
		}
		*rlst = (*rlst)->next;
	}
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	lst;
	t_list	*first;
	t_list	*rlst;

	rlst = ft_lstnew("");
	if (!rlst)
		return (0);
	first = rlst;
	va_start(lst, str);
	check_char(str, lst, &rlst);
	va_end(lst);
	rlst = first;
	len = print_result(rlst, FD);
	ft_lstclear(&first, del);
	return (len);
}
