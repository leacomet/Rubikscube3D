/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:27:45 by ecorvisi          #+#    #+#             */
/*   Updated: 2022/11/04 18:50:00 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_number(char const *s, char c)
{
	int		i;
	size_t	wordnb;

	i = 0;
	wordnb = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			wordnb++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (wordnb);
}

static char	**fill_tab(char const *s, char c, char **tabstr)
{
	size_t	i;
	size_t	j;
	size_t	wordlen;

	i = 0;
	j = 0;
	while (s[i])
	{
		wordlen = 0;
		while (s[i] && s[i] != c)
		{
			wordlen++;
			i++;
		}
		if (wordlen > 0)
		{
			tabstr[j] = ft_substr(s, i - wordlen, wordlen);
			if (!tabstr)
				return (NULL);
			j++;
		}
		if (s[i])
			i++;
	}
	return (tabstr);
}

char	**ft_split(char const *s, char c)
{
	char	**tabstr;
	size_t	wordnb;

	if (!s)
		return (NULL);
	wordnb = word_number(s, c);
	tabstr = ft_calloc(wordnb + 1, sizeof(char *));
	if (!tabstr)
		return (NULL);
	tabstr = fill_tab(s, c, tabstr);
	return (tabstr);
}
