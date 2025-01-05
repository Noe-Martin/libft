/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:30:33 by nmartin           #+#    #+#             */
/*   Updated: 2024/11/18 17:45:07 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (dst[y] && y < siz)
	{
		y++;
	}
	if (y == siz)
		return (siz + ft_strlen(src));
	while (src[i] && i + y + 1 < siz)
	{
		dst[i + y] = src[i];
		i++;
	}
	dst[i + y] = '\0';
	return (ft_strlen(src) + y);
}
