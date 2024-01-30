/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:29:53 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/07/17 19:20:34 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_tab(char **tab)
{
	int		i;
	char	**dup_tab;

	dup_tab = ft_calloc(ft_strlen_tab(tab) + 1, sizeof(char **));
	if (!dup_tab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		dup_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	return (dup_tab);
}
