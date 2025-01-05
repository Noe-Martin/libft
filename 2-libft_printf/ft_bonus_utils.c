/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:29:22 by nmartin           #+#    #+#             */
/*   Updated: 2024/12/05 16:41:05 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	b_hashtag(const char *bns, char *str, unsigned int nb)
{
	if (b_check('#', bns) && nb)
		ft_strlcpy(str, "0x", 3);
}

int	is_hashtag(const char *bns)
{
	if (b_check('#', bns))
		return (2);
	return (0);
}

int	b_digit(const char *bns)
{
	int	spaces;

	spaces = b_check_d(bns);
	if (spaces < 0)
		return (0);
	return (spaces);
}
