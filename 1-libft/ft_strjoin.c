/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:52:34 by nmartin           #+#    #+#             */
/*   Updated: 2024/11/24 13:04:43 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		y;
	char	*str;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		str[i + y] = s2[y];
		y++;
	}
	str[i + y] = '\0';
	return (str);
}
