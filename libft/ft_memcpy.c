/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:13:36 by ecorvisi          #+#    #+#             */
/*   Updated: 2022/10/19 16:01:27 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*final;

	str = (unsigned char *)src;
	final = (unsigned char *)dest;
	i = 0;
	if (src == NULL && dest == NULL)
		return (0);
	if (src == dest)
		return (dest);
	while (i < n)
	{
		final[i] = str[i];
		i++;
	}
	return (final);
}
