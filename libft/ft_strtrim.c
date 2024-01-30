/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:06:15 by ecorvisi          #+#    #+#             */
/*   Updated: 2022/10/22 14:47:07 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_count(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	char const	*tmp;

	i = 0;
	j = 0;
	while (ft_is_set(s1[i], set) == 0)
		i++;
	if (s1[i] != '\0')
	{
		tmp = &s1[i];
		j = ft_strlen(tmp);
		while (ft_is_set(tmp[j - 1], set) == 0)
			j--;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	len = ft_count(s1, set);
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_is_set(s1[i], set) == 0)
		i++;
	while (j < len)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	return (str);
}
