/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:59:29 by ecorvisi          #+#    #+#             */
/*   Updated: 2022/10/25 15:38:00 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sizesrc;
	size_t	sizedst;
	size_t	i;

	sizesrc = ft_strlen(src);
	if (size == 0)
		return (sizesrc);
	sizedst = ft_strlen(dst);
	if (sizedst >= size)
		return (sizesrc + size);
	i = 0;
	while (i + sizedst < size - 1 && src[i])
	{
		dst[sizedst + i] = src[i];
		i++;
	}
	dst[sizedst + i] = '\0';
	return (sizesrc + sizedst);
}
