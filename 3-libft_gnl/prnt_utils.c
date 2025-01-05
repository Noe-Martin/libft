/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:02:40 by nmartin           #+#    #+#             */
/*   Updated: 2025/01/05 12:23:45 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ftp_hlen(unsigned long long nbr)
{
	int	i;

	i = 1;
	while (nbr / 16 > 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

int	ftp_ilen(long long nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr / 10 > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	ftp_str_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

int	ftp_hex_p(char *str, unsigned long long nb, int is_bns, t_list **rlst)
{
	int		i;
	char	*base;

	if (!nb)
		is_bns = 0;
	i = ftp_hlen(nb) + is_bns;
	base = ft_strdup("0123456789abcdefg");
	if (!base)
	{
		ftp_str_error(rlst);
		return (0);
	}
	str[i--] = '\0';
	str[i--] = base[nb % 16];
	while (nb / 16 > 0)
	{
		nb /= 16;
		str[i--] = base[nb % 16];
	}
	free(base);
	return (1);
}

void	ftp_nbr_p(char *str, long long nb, int is_bonus)
{
	int	i;

	i = ftp_ilen(nb) + is_bonus;
	str[i--] = '\0';
	if (nb >= 0 && is_bonus)
		str[0] = '+';
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	str[i--] = nb % 10 + '0';
	while (nb / 10 > 0)
	{
		nb /= 10;
		str[i--] = nb % 10 + '0';
	}
}
