/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:31:57 by nmartin           #+#    #+#             */
/*   Updated: 2024/11/19 11:38:48 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && len > 0)
	{
		y = 0;
		while (big [i + y] == little[y] && i + y < len)
		{
			y++;
			if (little [y] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
