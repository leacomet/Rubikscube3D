/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:03:10 by ecorvisi          #+#    #+#             */
/*   Updated: 2022/11/10 02:23:55 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	wordlen;

	i = 0;
	if (!big && !len)
		return (0);
	if (little[0] == '\0')
		return ((char *)big);
	wordlen = ft_strlen(little) - 1;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (j == wordlen)
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
