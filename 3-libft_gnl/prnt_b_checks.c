/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_b_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:06:49 by nmartin           #+#    #+#             */
/*   Updated: 2025/01/05 12:00:32 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ftp_b_str_dot(const char *bns, char *str, int check_null)
{
	int		i;
	char	*bns_limited;
	char	*result;

	i = ftp_b_check_d(&bns[ftp_b_dot_b(bns)]);
	if (i < 1 || (check_null && i < 6))
		ft_bzero(str, ft_strlen(str));
	else if (i < (int)ft_strlen(str))
		ft_bzero(&str[i], ft_strlen(&str[i]));
	bns_limited = malloc(sizeof(char) * (ftp_b_dot_b(bns) + 1));
	if (!bns_limited)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(bns_limited, bns, ftp_b_dot_b(bns) + 1);
	result = ftp_b_is_digit(bns_limited, str);
	free(bns_limited);
	return (result);
}

int	ftp_b_dot_b(const char *str)
{
	int	i;

	i = 1;
	if (!ftp_b_check('.', str))
		return (0);
	while (str[i] != '.')
		i++;
	return (i);
}

char	*ftp_b_is_dot_nb(const char *bns, char *str, int is_zero)
{
	int		dot;
	char	*result;

	dot = 0;
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
		dot = 1;
	if (is_zero)
		ft_bzero(&str[dot], ft_strlen(&str[dot]));
	result = ftp_b_is_zero(&bns[ftp_b_dot_b(bns)], str, dot);
	result = ftp_b_is_digit(bns, result);
	return (result);
}

char	*ftp_b_is_zero(const char *bns, char *str, int dot)
{
	int		spaces;
	char	*width;
	char	*result;

	if (ftp_b_check('-', bns))
		return (ftp_b_is_digit(bns, str));
	spaces = ftp_b_digit(bns) - ft_strlen(str) + dot;
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

char	*ftp_b_is_digit(const char *bns, char *str)
{
	int		spaces;
	char	*width;
	char	*result;

	spaces = ftp_b_digit(bns) - ft_strlen(str);
	if (spaces < 1)
		return (str);
	width = malloc(sizeof(char) * (spaces + 1));
	if (!width)
		return (NULL);
	width[spaces--] = '\0';
	while (spaces >= 0)
		width[spaces--] = ' ';
	if (ftp_b_check('-', bns))
		result = ft_strjoin(str, width);
	else
		result = ft_strjoin(width, str);
	free(width);
	free(str);
	return (result);
}
