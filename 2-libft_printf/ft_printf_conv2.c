/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:55:37 by nmartin           #+#    #+#             */
/*   Updated: 2024/12/05 19:25:32 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prnt_i(int nb, const char *bns, t_list **rlst)
{
	int		bns_len;
	char	*i_content;

	bns_len = 0;
	if ((b_check(' ', bns) || (b_check('+', bns))) && nb >= 0)
		bns_len = 1;
	i_content = malloc(sizeof(char) * (int_len(nb) + bns_len + 1));
	if (!i_content)
	{
		str_error(rlst);
		return ;
	}
	nbr_p(i_content, nb, bns_len);
	if (!b_check('+', bns) && b_check(' ', bns) && nb >= 0)
		i_content[0] = ' ';
	if (b_check('.', bns) && nb != 0)
		(*rlst)->content = b_is_dot_nb(bns, i_content, 0);
	else if (b_check('.', bns) && nb == 0)
		(*rlst)->content = b_is_dot_nb(bns, i_content, 1);
	else if (b_check('0', bns))
		(*rlst)->content = b_is_zero(bns, i_content, 0);
	else
		(*rlst)->content = b_is_digit(bns, i_content);
	if (!(*rlst)->content)
		str_error(rlst);
}

void	prnt_x(unsigned long long nb, int up, const char *bns, t_list **rlst)
{
	char	*x_content;

	if (nb == 0)
		x_content = malloc(sizeof(char) * 2);
	else
		x_content = malloc(sizeof(char) * (hex_len(nb) + is_hashtag(bns) + 1));
	if (!x_content)
		str_error(rlst);
	if (!x_content)
		return ;
	b_hashtag(bns, x_content, nb);
	if (!hex_p(x_content, nb, is_hashtag(bns), rlst))
		return ;
	if (up)
		str_upper(x_content);
	if (b_check('.', bns) && nb != 0)
		(*rlst)->content = b_is_dot_nb(bns, x_content, 0);
	else if (b_check('.', bns) && nb == 0)
		(*rlst)->content = b_is_dot_nb(bns, x_content, 1);
	else if (b_check('0', bns))
		(*rlst)->content = b_is_zero(bns, x_content, 0);
	else
		(*rlst)->content = b_is_digit(bns, x_content);
	if (!(*rlst)->content)
		str_error(rlst);
}

void	prnt_u(unsigned int nb, const char *bns, t_list **rlst)
{
	char	*u_content;

	u_content = malloc(sizeof(char) * (int_len(nb) + 1));
	if (!u_content)
	{
		str_error(rlst);
		return ;
	}
	nbr_p(u_content, nb, 0);
	if (b_check('.', bns) && nb != 0)
		(*rlst)->content = b_is_dot_nb(bns, u_content, 0);
	else if (b_check('.', bns) && nb == 0)
		(*rlst)->content = b_is_dot_nb(bns, u_content, 1);
	else if (b_check('0', bns))
		(*rlst)->content = b_is_zero(bns, u_content, 0);
	else
		(*rlst)->content = b_is_digit(bns, u_content);
	if (!(*rlst)->content)
		str_error(rlst);
}
