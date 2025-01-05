/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:47:35 by nmartin           #+#    #+#             */
/*   Updated: 2024/12/05 19:56:42 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prnt_c(char c, const char *bns, t_list **rlst)
{
	char	*c_content;

	if (!c)
	{
		(*rlst)->content = NULL;
		if (b_check_d(bns) > 1)
			c_null(bns, rlst);
		return ;
	}
	c_content = malloc(sizeof(char) * 2);
	if (!c_content)
	{
		str_error(rlst);
		return ;
	}
	c_content[0] = c;
	c_content[1] = '\0';
	(*rlst)->content = b_is_digit(bns, c_content);
}

void	prnt_s(char *str, const char *bns, t_list **rlst)
{
	int		check_null;
	char	*s_content;

	check_null = 0;
	if (!str)
	{
		s_content = ft_strdup("(null)");
		check_null = 1;
	}
	else
		s_content = ft_strdup(str);
	if (!s_content)
	{
		str_error(rlst);
		return ;
	}
	if (b_check('.', bns))
		(*rlst)->content = b_str_dot(bns, s_content, check_null);
	else
		(*rlst)->content = b_is_digit(bns, s_content);
	if ((*rlst)->content == NULL)
		str_error(rlst);
}

void	prnt_p(unsigned long long ptr, const char *bns, t_list **rlst)
{
	char	*p_content;

	if (!ptr)
		p_content = ft_strdup("(nil)");
	else
		p_content = malloc(sizeof(char) * (hex_len(ptr) + 3));
	if (!p_content)
	{
		str_error(rlst);
		return ;
	}
	if (ptr)
	{
		ft_strlcpy(p_content, "0x", 3);
		if (!hex_p(&p_content[2], ptr, 0, rlst))
			return ;
	}
	(*rlst)->content = b_is_digit(bns, p_content);
	if ((*rlst)->content == NULL)
		str_error(rlst);
}

void	prnt_percent(t_list **rlst)
{
	char	*txt;

	txt = malloc(sizeof(char) * (2));
	if (!txt)
	{
		str_error(rlst);
		return ;
	}
	txt[0] = '%';
	txt[1] = '\0';
	(*rlst)->content = txt;
}
