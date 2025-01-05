/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_conv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:47:35 by nmartin           #+#    #+#             */
/*   Updated: 2025/01/05 11:57:49 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ftp_c(char c, const char *bns, t_list **rlst)
{
	char	*c_content;

	if (!c)
	{
		(*rlst)->content = NULL;
		if (ftp_b_check_d(bns) > 1)
			ftp_c_null(bns, rlst);
		return ;
	}
	c_content = malloc(sizeof(char) * 2);
	if (!c_content)
	{
		ftp_str_error(rlst);
		return ;
	}
	c_content[0] = c;
	c_content[1] = '\0';
	(*rlst)->content = ftp_b_is_digit(bns, c_content);
}

void	ftp_s(char *str, const char *bns, t_list **rlst)
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
		ftp_str_error(rlst);
		return ;
	}
	if (ftp_b_check('.', bns))
		(*rlst)->content = ftp_b_str_dot(bns, s_content, check_null);
	else
		(*rlst)->content = ftp_b_is_digit(bns, s_content);
	if ((*rlst)->content == NULL)
		ftp_str_error(rlst);
}

void	ftp_p(unsigned long long ptr, const char *bns, t_list **rlst)
{
	char	*p_content;

	if (!ptr)
		p_content = ft_strdup("(nil)");
	else
		p_content = malloc(sizeof(char) * (ftp_hlen(ptr) + 3));
	if (!p_content)
	{
		ftp_str_error(rlst);
		return ;
	}
	if (ptr)
	{
		ft_strlcpy(p_content, "0x", 3);
		if (!ftp_hex_p(&p_content[2], ptr, 0, rlst))
			return ;
	}
	(*rlst)->content = ftp_b_is_digit(bns, p_content);
	if ((*rlst)->content == NULL)
		ftp_str_error(rlst);
}

void	ftp_percent(t_list **rlst)
{
	char	*txt;

	txt = malloc(sizeof(char) * (2));
	if (!txt)
	{
		ftp_str_error(rlst);
		return ;
	}
	txt[0] = '%';
	txt[1] = '\0';
	(*rlst)->content = txt;
}
