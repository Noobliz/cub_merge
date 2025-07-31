/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiet <lguiet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:42:35 by lguiet            #+#    #+#             */
/*   Updated: 2024/10/18 15:41:55 by lguiet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	words_nb(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static char	*word_copy(const char *s, int size)
{
	char	*word;

	word = malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, size + 1);
	return (word);
}

static	void	ft_free(char **s1, int words)
{
	while (words >= 0)
	{
		free(s1[words]);
		words--;
	}
	free(s1);
}

static char	**copied(const char *s, char c, char **tab_tab, int words)
{
	int		i;
	int		j;
	char	*start;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = (char *) s + i;
		while (s[i] && s[i] != c)
			i++;
		if (s + i > start)
		{
			tab_tab[j] = word_copy(start, s + i - start);
			if (tab_tab[j] == NULL)
				ft_free(tab_tab, words);
			j++;
		}
	}
	tab_tab[j] = NULL;
	return (tab_tab);
}

char	**ft_split(const char *s, char c)
{
	char	**words_split;
	int		words;

	if (!s)
		return (NULL);
	words = words_nb(s, c);
	words_split = malloc(sizeof(char *) * (words + 1));
	if (!words_split)
		return (NULL);
	copied(s, c, words_split, words);
	return (words_split);
}
