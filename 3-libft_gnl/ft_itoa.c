/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:26:50 by nmartin           #+#    #+#             */
/*   Updated: 2024/11/15 16:21:58 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

int	itoa_len(long nb)
{
	int	len;

	len = 1;
	if (nb < 0)
		nb = -nb;
	while (nb / 10 > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	str_init(char *str, int len, int is_negative)
{
	int	i;

	i = 0;
	if (is_negative)
		str[i++] = '-';
	while (i <= len)
	{
		str[i++] = '0';
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*str;

	nb = (long)n;
	str = malloc(sizeof(char) * (itoa_len(nb) + is_negative(n) + 1));
	if (str == NULL)
		return (NULL);
	i = itoa_len(nb) + is_negative(n) - 1;
	if (is_negative(nb))
		nb = -nb;
	str_init(str, i, is_negative(n));
	while (i >= is_negative(n))
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
/*#include <stdio.h>
int	main (void)
{
	printf("%s\n", ft_itoa(-545124));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-0));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	return (0);
}*/
