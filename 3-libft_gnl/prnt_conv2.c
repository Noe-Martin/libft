/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_conv2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:55:37 by nmartin           #+#    #+#             */
/*   Updated: 2025/01/05 12:22:56 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ftp_i(int nb, const char *bns, t_list **rlst)
{
	int		bns_len;
	char	*i_content;

	bns_len = 0;
	if ((ftp_b_check(' ', bns) || (ftp_b_check('+', bns))) && nb >= 0)
		bns_len = 1;
	i_content = malloc(sizeof(char) * (ftp_ilen(nb) + bns_len + 1));
	if (!i_content)
	{
		ftp_str_error(rlst);
		return ;
	}
	ftp_nbr_p(i_content, nb, bns_len);
	if (!ftp_b_check('+', bns) && ftp_b_check(' ', bns) && nb >= 0)
		i_content[0] = ' ';
	if (ftp_b_check('.', bns) && nb != 0)
		(*rlst)->content = ftp_b_is_dot_nb(bns, i_content, 0);
	else if (ftp_b_check('.', bns) && nb == 0)
		(*rlst)->content = ftp_b_is_dot_nb(bns, i_content, 1);
	else if (ftp_b_check('0', bns))
		(*rlst)->content = ftp_b_is_zero(bns, i_content, 0);
	else
		(*rlst)->content = ftp_b_is_digit(bns, i_content);
	if (!(*rlst)->content)
		ftp_str_error(rlst);
}

void	ftp_x(unsigned long long nb, int up, const char *b, t_list **rlst)
{
	char	*x_content;

	if (nb == 0)
		x_content = malloc(sizeof(char) * 2);
	else
		x_content = malloc(sizeof(char) * (ftp_hlen(nb) + ftp_hashtag(b) + 1));
	if (!x_content)
		ftp_str_error(rlst);
	if (!x_content)
		return ;
	ftp_b_hashtag(b, x_content, nb);
	if (!ftp_hex_p(x_content, nb, ftp_hashtag(b), rlst))
		return ;
	if (up)
		ftp_str_upper(x_content);
	if (ftp_b_check('.', b) && nb != 0)
		(*rlst)->content = ftp_b_is_dot_nb(b, x_content, 0);
	else if (ftp_b_check('.', b) && nb == 0)
		(*rlst)->content = ftp_b_is_dot_nb(b, x_content, 1);
	else if (ftp_b_check('0', b))
		(*rlst)->content = ftp_b_is_zero(b, x_content, 0);
	else
		(*rlst)->content = ftp_b_is_digit(b, x_content);
	if (!(*rlst)->content)
		ftp_str_error(rlst);
}

void	ftp_u(unsigned int nb, const char *bns, t_list **rlst)
{
	char	*u_content;

	u_content = malloc(sizeof(char) * (ftp_ilen(nb) + 1));
	if (!u_content)
	{
		ftp_str_error(rlst);
		return ;
	}
	ftp_nbr_p(u_content, nb, 0);
	if (ftp_b_check('.', bns) && nb != 0)
		(*rlst)->content = ftp_b_is_dot_nb(bns, u_content, 0);
	else if (ftp_b_check('.', bns) && nb == 0)
		(*rlst)->content = ftp_b_is_dot_nb(bns, u_content, 1);
	else if (ftp_b_check('0', bns))
		(*rlst)->content = ftp_b_is_zero(bns, u_content, 0);
	else
		(*rlst)->content = ftp_b_is_digit(bns, u_content);
	if (!(*rlst)->content)
		ftp_str_error(rlst);
}
