/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:04:52 by nmartin           #+#    #+#             */
/*   Updated: 2025/01/05 12:20:25 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ftp_printer(char *str, int fd)
{
	if (!str)
	{
		ft_putchar_fd('\0', fd);
		return (1);
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

int	ftp_print_result(t_list *lst, int fd)
{
	int		len;
	char	*str;

	len = 0;
	while (lst)
	{
		str = (char *)(lst->content);
		len += ftp_printer(str, fd);
		lst = lst->next;
	}
	return (len);
}

int	ftp_print_txt(const char *str, t_list **rlst)
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
		ftp_str_error(rlst);
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

void	ftp_check_char(const char *str, va_list lst, t_list **rlst)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			i += ftp_print_txt(&str[i], rlst);
		else
			i += ftp_printf_conv(&str[i], lst, rlst);
		if (!(*rlst) || !str[i])
			return ;
		(*rlst)->next = ft_lstnew("");
		if (!(*rlst)->next)
		{
			ftp_str_error(&((*rlst)->next));
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
	ftp_check_char(str, lst, &rlst);
	va_end(lst);
	rlst = first;
	len = ftp_print_result(rlst, FD);
	ft_lstclear(&first, ftp_del);
	return (len);
}
