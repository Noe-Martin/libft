/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:33:10 by nmartin           #+#    #+#             */
/*   Updated: 2024/12/03 13:49:10 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_null(const char *bns, t_list **rlst)
{
	int		spaces;
	char	c;
	char	*width;

	spaces = b_digit(bns) - 1;
	if (spaces < 1)
	{
		str_error(rlst);
		return ;
	}
	width = malloc(sizeof(char) * (spaces + 1));
	if (!width)
	{
		str_error(rlst);
		return ;
	}
	c = ' ';
	if (int_len(b_check_d(bns)) - b_check('0', bns) > int_len(b_check_d(bns)))
		c = '0';
	width[spaces--] = '\0';
	while (spaces >= 0)
		width[spaces--] = c;
	put_spaces(b_check('-', bns), rlst, width);
}

void	put_spaces(int is_minus, t_list **rlst, char *width)
{
	(*rlst)->content = NULL;
	if (!is_minus)
		(*rlst)->content = width;
	(*rlst)->next = ft_lstnew("");
	if (!(*rlst)->next)
	{
		str_error(&((*rlst)->next));
		return ;
	}
	*rlst = (*rlst)->next;
	(*rlst)->content = NULL;
	if (is_minus)
		(*rlst)->content = width;
}

void	str_error(t_list **result)
{
	*result = NULL;
}

void	del(void *content)
{
	free(content);
}
