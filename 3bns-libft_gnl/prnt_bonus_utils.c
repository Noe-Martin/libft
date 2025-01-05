/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_bonus_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:29:22 by nmartin           #+#    #+#             */
/*   Updated: 2025/01/05 11:59:36 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ftp_b_hashtag(const char *bns, char *str, unsigned int nb)
{
	if (ftp_b_check('#', bns) && nb)
		ft_strlcpy(str, "0x", 3);
}

int	ftp_hashtag(const char *b)
{
	if (ftp_b_check('#', b))
		return (2);
	return (0);
}

int	ftp_b_digit(const char *bns)
{
	int	spaces;

	spaces = ftp_b_check_d(bns);
	if (spaces < 0)
		return (0);
	return (spaces);
}
