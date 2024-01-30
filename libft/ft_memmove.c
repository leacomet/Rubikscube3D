/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:13:08 by ecorvisi          #+#    #+#             */
/*   Updated: 2022/10/19 16:01:40 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*final;

	str = (unsigned char *)src;
	final = (unsigned char *)dest;
	i = 0;
	if (src == NULL && dest == NULL)
		return (0);
	if (dest > src)
	{
		while (n > 0)
		{
			final[n - 1] = str[n - 1];
			n--;
		}
		return (final);
	}
	while (i < n)
	{
		final[i] = str[i];
		i++;
	}
	return (final);
}
