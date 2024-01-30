/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:18:20 by ecorvisi          #+#    #+#             */
/*   Updated: 2022/10/25 12:46:46 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	find;
	size_t			i;

	find = (unsigned char )c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == find)
			return (str + i);
		i++;
	}	
	return (NULL);
}
