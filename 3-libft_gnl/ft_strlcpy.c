/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:25:20 by nmartin           #+#    #+#             */
/*   Updated: 2024/11/18 17:49:32 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	i = 0;
	if (siz > 0)
	{
		while (i < siz - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*#include <stdio.h>
int	main (void)
  {
  char	str[] = "123456789";
  char	dest[] = "abc";
  printf("%d\n", (int)ft_strlcpy(dest, "", 15));
  printf("%s\n", dest);
  printf("%s\n", str);
  return (0);
  }*/
