/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_without_nl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:28:54 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/03 15:16:30 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strdup_cub(const char *s)
{
	char	*dup;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	dup = malloc(sizeof (char) * len + 1);
	if (dup == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
