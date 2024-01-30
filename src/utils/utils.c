/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:22:49 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/19 13:31:56 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

char	*ft_strdup_start(char *str, int start)
{
	char	*dup;
	int		i;

	i = 0;
	while (str[i])
		i++;
	i = i - start;
	dup = malloc(sizeof (char) * i + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[start] != '\0' && str[start] != '\n')
	{
		dup[i] = str[start];
		start++;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_strdup_tab_start(char **tab, int start)
{
	int		i;
	char	**dup_tab;

	i = ft_strlen_tab(tab) - start;
	dup_tab = ft_calloc(i + 1, sizeof(char **));
	if (!dup_tab)
		return (NULL);
	i = 0;
	while (tab[start])
	{
		dup_tab[i] = ft_strdup_start(tab[start], 0);
		start++;
		i++;
	}
	return (dup_tab);
}
