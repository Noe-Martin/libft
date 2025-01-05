/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:02:40 by nmartin           #+#    #+#             */
/*   Updated: 2024/12/05 18:00:31 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned long long nbr)
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

int	int_len(long long nbr)
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

void	str_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

int	hex_p(char *str, unsigned long long nb, int is_bonus, t_list **rlst)
{
	int		i;
	char	*base;

	if (!nb)
		is_bonus = 0;
	i = hex_len(nb) + is_bonus;
	base = ft_strdup("0123456789abcdefg");
	if (!base)
	{
		str_error(rlst);
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

void	nbr_p(char *str, long long nb, int is_bonus)
{
	int	i;

	i = int_len(nb) + is_bonus;
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
