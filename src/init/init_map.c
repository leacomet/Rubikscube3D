/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:37:53 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/20 14:44:45 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_if_double_map(char **split, int i)
{
	int	j;

	j = i;
	while (split[j] && ft_strlen(split[j]) > 0)
		j++;
	while (split[j])
	{
		if (ft_strchr(split[j], '1') != NULL || ft_strchr(split[j], '0') != NULL
			|| ft_strchr(split[j], 'N') != NULL
			|| ft_strchr(split[j], 'S') != NULL
			|| ft_strchr(split[j], 'W') != NULL
			|| ft_strchr(split[j], 'E') != NULL)
			return (1);
		j++;
	}
	return (0);
}

int	init_map(t_game *game, char **split, int i)
{
	if (check_if_double_map(split, i) == 1)
	{
		ft_putstr_fd("Error\nDouble map detected\n", 2);
		return (1);
	}
	game->map = ft_strdup_tab_start(split, i);
	return (0);
}
