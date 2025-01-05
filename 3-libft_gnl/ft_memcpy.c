/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:43:23 by nmartin           #+#    #+#             */
/*   Updated: 2024/11/19 17:19:35 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*strsrc;
	char	*strdest;

	i = 0;
	strsrc = (char *)src;
	strdest = (char *)dest;
	if (src == dest)
		return (dest);
	while (i < (int)n)
	{
		strdest[i] = strsrc[i];
		i++;
	}
	return (dest);
}
