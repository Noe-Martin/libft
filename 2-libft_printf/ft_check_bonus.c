/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:40:36 by nmartin           #+#    #+#             */
/*   Updated: 2024/12/06 13:56:18 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	b_check(char c, const char *str)
{
	int	i;

	i = 1;
	while (str[i] && str[i] != 'c' && str[i] != 's' && str[i] != 'p'
		&& str[i] != 'd' && str[i] != 'u' && str[i] != 'i'
		&& str[i] != 'x' && str[i] != 'X' && str[i] != '%')
	{
		if (str[i] == c && c == '0')
		{
			if (ft_isdigit(str[i - 1])
				|| str[i + 1] == '.' || str[i - 1] == '.')
				return (0);
			return (1);
		}
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	b_check_d(const char *str)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (str[i] && str[i] != 'c' && str[i] != 's' && str[i] != 'p'
		&& str[i] != 'd' && str[i] != 'u' && str[i] != 'i'
		&& str[i] != 'x' && str[i] != 'X' && str[i] != '%')
	{
		if (str[i] == '0' && str[i + 1] != '.' && str[i - 1] != '.')
			i++;
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
			{
				y *= 10;
				y += (str[i++] - '0') % 10;
			}
			return (y);
		}
		i++;
	}
	return (-1);
}

int	b_len_d(const char *str)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (str[i] && str[i] != 'c' && str[i] != 's' && str[i] != 'p'
		&& str[i] != 'd' && str[i] != 'u' && str[i] != 'i'
		&& str[i] != 'x' && str[i] != 'X' && str[i] != '%')
	{
		if (str[i] == '0' && str[i - 1] != '.')
			i++;
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i++]))
				y++;
			return (y);
		}
		i++;
	}
	return (-1);
}

int	is_bonus(const char *str)
{
	int	i;

	i = 0;
	if (b_check('-', str))
		i++;
	if (b_check('0', str))
		i++;
	if (b_check('.', str))
		i++;
	if (b_check('#', str))
		i++;
	if (b_check(' ', str))
		i++;
	if (b_check('+', str))
		i++;
	if (b_check_d(str) == -1)
		return (i);
	if (b_check_d(&str[b_dot_b(str)]) != -1)
		i += b_len_d(&str[b_dot_b(str)]);
	if (ft_isdigit(str[b_dot_b(str) - 1]))
		i += b_len_d(str);
	return (i);
}
