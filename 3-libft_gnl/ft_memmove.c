/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:12:26 by nmartin           #+#    #+#             */
/*   Updated: 2024/11/18 11:57:59 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*strsrc;
	char	*strdest;

	strsrc = (char *)src;
	strdest = (char *)dest;
	if (strdest > strsrc)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			strdest[i] = strsrc[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
