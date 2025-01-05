/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:15:16 by nmartin           #+#    #+#             */
/*   Updated: 2024/11/18 19:51:02 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < (int)n)
	{
		if (str[i] == (char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
