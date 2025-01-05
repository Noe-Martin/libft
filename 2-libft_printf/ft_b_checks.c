/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:06:49 by nmartin           #+#    #+#             */
/*   Updated: 2024/12/06 13:35:30 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*b_str_dot(const char *bns, char *str, int check_null)
{
	int		i;
	char	*bns_limited;
	char	*result;

	i = b_check_d(&bns[b_dot_b(bns)]);
	if (i < 1 || (check_null && i < 6))
		ft_bzero(str, ft_strlen(str));
	else if (i < (int)ft_strlen(str))
		ft_bzero(&str[i], ft_strlen(&str[i]));
	bns_limited = malloc(sizeof(char) * (b_dot_b(bns) + 1));
	if (!bns_limited)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(bns_limited, bns, b_dot_b(bns) + 1);
	result = b_is_digit(bns_limited, str);
	free(bns_limited);
	return (result);
}

int	b_dot_b(const char *str)
{
	int	i;

	i = 1;
	if (!b_check('.', str))
		return (0);
	while (str[i] != '.')
		i++;
	return (i);
}

char	*b_is_dot_nb(const char *bns, char *str, int is_zero)
{
	int		dot;
	char	*result;

	dot = 0;
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
		dot = 1;
	if (is_zero)
		ft_bzero(&str[dot], ft_strlen(&str[dot]));
	result = b_is_zero(&bns[b_dot_b(bns)], str, dot);
	result = b_is_digit(bns, result);
	return (result);
}

char	*b_is_zero(const char *bns, char *str, int dot)
{
	int		spaces;
	char	*width;
	char	*result;

	if (b_check('-', bns))
		return (b_is_digit(bns, str));
	spaces = b_digit(bns) - ft_strlen(str) + dot;
	if (spaces < 1)
		return (str);
	width = malloc(sizeof(char) * (spaces + 1));
	if (!width)
		return (NULL);
	width[spaces--] = '\0';
	while (spaces >= 0)
		width[spaces--] = '0';
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
	{
		width[0] = str[0];
		str[0] = '0';
	}
	result = ft_strjoin(width, str);
	free(width);
	free(str);
	return (result);
}

char	*b_is_digit(const char *bns, char *str)
{
	int		spaces;
	char	*width;
	char	*result;

	spaces = b_digit(bns) - ft_strlen(str);
	if (spaces < 1)
		return (str);
	width = malloc(sizeof(char) * (spaces + 1));
	if (!width)
		return (NULL);
	width[spaces--] = '\0';
	while (spaces >= 0)
		width[spaces--] = ' ';
	if (b_check('-', bns))
		result = ft_strjoin(str, width);
	else
		result = ft_strjoin(width, str);
	free (width);
	free (str);
	return (result);
}
