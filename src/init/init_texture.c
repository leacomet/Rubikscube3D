/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:40:21 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/20 16:25:46 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_texture_2(char *str, t_game *game, int k, int i)
{
	if (str[k] == 'F')
	{
		game->floor->rgb_line = ft_recover_rgb(str, i);
		if (!game->floor->rgb_line)
			ft_exit_game(str, game);
	}
	else if (str[k] == 'C')
	{
		game->ceiling->rgb_line = ft_recover_rgb(str, i);
		if (!game->ceiling->rgb_line)
			ft_exit_game(str, game);
	}
}

void	ft_init_texture(char *str, t_game *game)
{
	int	i;
	int	k;

	i = 0;
	while (str[i] && is_white_space(str[i]) == 1)
		i++;
	k = i;
	while (str[i] && is_white_space(str[i]) == 0)
		i++;
	while (str[i] && is_white_space(str[i]) == 1)
		i++;
	if (str[k] == 'N' && str[k + 1] != '\0' && str[k + 1] == 'O')
		game->north->pathfile = ft_strdup_start(str, i);
	else if (str[k] == 'S' && str[k + 1] != '\0' && str[k + 1] == 'O')
		game->south->pathfile = ft_strdup_start(str, i);
	else if (str[k] == 'W' && str[k + 1] != '\0' && str[k + 1] == 'E')
		game->west->pathfile = ft_strdup_start(str, i);
	else if (str[k] == 'E' && str[k + 1] != '\0' && str[k + 1] == 'A')
		game->east->pathfile = ft_strdup_start(str, i);
	else
		ft_init_texture_2(str, game, k, i);
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_white_space(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_if_texture(t_game *game, char **split)
{
	int	i;

	i = 0;
	while (split[i] && check_if_wall(split[i]) == 0)
	{
		if (is_texture(split[i]) == 0)
		{
			if (ft_check_if_double_texture(game, split[i]) == 1)
				return (return_error_texture(-1, split,
						"Error\nDouble texture\n"));
			ft_init_texture(split[i], game);
		}
		else if (check_line(split[i]) == 1)
			return (return_error_texture(-1, split,
					"Error\nNot only texture before map\n"));
		i++;
	}
	return (i);
}

int	ft_init_game_texture(t_game *game, char **split)
{
	int	i;

	i = ft_check_if_texture(game, split);
	if (i == -1)
		return (1);
	if (check_texture(game) == 1)
	{
		ft_free_tab(split);
		return (1);
	}
	ft_valid_rgb(game->floor);
	ft_valid_rgb(game->ceiling);
	while (split[i] && ft_strchr(split[i], '1') == NULL)
		i++;
	if (init_map(game, split, i) == 1)
	{
		ft_free_tab(split);
		return (1);
	}
	ft_free_tab(split);
	return (0);
}
