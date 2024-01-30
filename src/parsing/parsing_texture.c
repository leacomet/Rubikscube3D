/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:30:48 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/20 14:50:04 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_rgb_texture(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			if (str[i + 1] != '\0' && str[i + 1] == ',')
				return (1);
			k++;
		}
		else if (ft_isdigit(str[i]) == 1)
			return (1);
		i++;
	}
	if (k > 2)
		return (1);
	return (0);
}

int	check_texture(t_game *game)
{
	if (!game->floor->rgb_line || !game->ceiling->rgb_line)
	{
		ft_putstr_fd("Error\nMissing texture or the map between texture\n", 2);
		return (1);
	}
	if (ft_strcmp(game->floor->rgb_line, "error") == 0
		|| ft_strcmp(game->ceiling->rgb_line, "error") == 0)
		return (1);
	if (check_rgb_texture(game->floor->rgb_line) == 1
		|| check_rgb_texture(game->ceiling->rgb_line) == 1)
	{
		ft_putstr_fd("Error\nNot valid RGB format\n", 2);
		return (1);
	}
	return (0);
}
