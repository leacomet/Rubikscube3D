/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:27:12 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/03 15:31:23 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_if_player(char **map)
{
	int	i;
	int	j;
	int	boolean;

	i = 0;
	boolean = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
					|| map[i][j] == 'E')
				boolean++;
			j++;
		}
		i++;
	}
	if (boolean == 0)
		return (1);
	else
		return (0);
}
