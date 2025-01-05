/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:40:00 by nmartin           #+#    #+#             */
/*   Updated: 2024/11/19 14:12:20 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_trim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		y;
	int		z;
	char	*str;

	i = 0;
	y = ft_strlen(s1);
	z = 0;
	while (s1[i] && is_trim(s1[i], set))
		i++;
	while (is_trim(s1[y - 1], set))
		y--;
	if (i >= y)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (y - i + 1));
	if (str == NULL)
		return (NULL);
	while (i <= y - 1)
		str[z++] = s1[i++];
	str[z] = '\0';
	return (str);
}
