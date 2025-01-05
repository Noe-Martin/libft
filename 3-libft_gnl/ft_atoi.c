/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:53:15 by nmartin           #+#    #+#             */
/*   Updated: 2025/01/04 14:56:01 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*is_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
	{
		i++;
	}
	return (&str[i]);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	nptr = is_space(nptr);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr [i] == '-')
			sign = -1;
		i++;
	}
	while (nptr [i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += nptr[i] - '0';
		i++;
	}
	return ((int)nb * sign);
}
