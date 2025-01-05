/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:09:05 by nmartin           #+#    #+#             */
/*   Updated: 2024/11/24 13:10:23 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
			{
				i++;
			}
		}
		if (str[i] && str[i] != c)
		{
			words++;
			while (str[i] && str[i] != c)
			{
				i++;
			}
		}
	}
	return (words);
}

int	word_len(char *str, char c, int	*y)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
	{
		i++;
	}
	if (str[i] && str[i] != c)
	{
		*y += i;
		while (str[i] && str[i] != c)
		{
			i++;
			len++;
		}
	}
	return (len);
}

char	**free_tab(char **tab, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		free(tab[i++]);
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		y;
	int		len;
	char	**tab;

	i = 0;
	y = 0;
	tab = malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (i < count_words((char *)s, c))
	{
		j = 0;
		len = word_len((char *)&s[y], c, &y);
		tab[i] = malloc(sizeof(char) * (len + 1));
		if (tab[i] == NULL)
			return (free_tab(tab, i));
		while (j < len)
			tab[i][j++] = s[y++];
		tab[i++][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	ac = 0;
	int	i = 0;
	char **tab = ft_split(av[1], av[2][0]);	
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		free(tab[i++]);
	}
	free(tab);
	return (0);
}*/
