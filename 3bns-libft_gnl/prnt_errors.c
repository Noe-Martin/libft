/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:33:10 by nmartin           #+#    #+#             */
/*   Updated: 2025/01/05 12:24:16 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ftp_c_null(const char *bns, t_list **rlst)
{
	int		spaces;
	char	c;
	char	*width;

	spaces = ftp_b_digit(bns) - 1;
	if (spaces < 1)
	{
		ftp_str_error(rlst);
		return ;
	}
	width = malloc(sizeof(char) * (spaces + 1));
	if (!width)
	{
		ftp_str_error(rlst);
		return ;
	}
	c = ' ';
	if (ftp_ilen(ftp_b_check_d(bns)) - ftp_b_check('0', bns)
		> ftp_ilen(ftp_b_check_d(bns)))
		c = '0';
	width[spaces--] = '\0';
	while (spaces >= 0)
		width[spaces--] = c;
	ftp_put_spaces(ftp_b_check('-', bns), rlst, width);
}

void	ftp_put_spaces(int is_minus, t_list **rlst, char *width)
{
	(*rlst)->content = NULL;
	if (!is_minus)
		(*rlst)->content = width;
	(*rlst)->next = ft_lstnew("");
	if (!(*rlst)->next)
	{
		ftp_str_error(&((*rlst)->next));
		return ;
	}
	*rlst = (*rlst)->next;
	(*rlst)->content = NULL;
	if (is_minus)
		(*rlst)->content = width;
}

void	ftp_str_error(t_list **result)
{
	*result = NULL;
}

void	ftp_del(void *content)
{
	free(content);
}
