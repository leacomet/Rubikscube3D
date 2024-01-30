/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:00:05 by ecorvisi          #+#    #+#             */
/*   Updated: 2022/10/19 16:02:33 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*buff;
	char	find;

	find = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == find)
		{
			buff = &((char *)s)[i];
			return (buff);
		}
		i--;
	}
	if (s[i] == find)
	{
		buff = &((char *)s)[i];
		return (buff);
	}
	return (NULL);
}
