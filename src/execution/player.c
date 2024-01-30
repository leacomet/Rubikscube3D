/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:16:18 by acomet            #+#    #+#             */
/*   Updated: 2023/10/20 17:13:44 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_player_position_follow(char direction, t_player *player,
		int x, int y)
{
	if (direction == 'E')
	{
		player->pa = 0;
		player->px = x * SQUARE_MAP + ((SQUARE_MAP + 1) / 2);
		player->py = y * SQUARE_MAP + ((SQUARE_MAP + 1) / 2);
		player->pdx = cos(player->pa);
		player->pdy = sin(player->pa);
		return (1);
	}
	else if (direction == 'W')
	{
		player->pa = PI;
		player->px = x * SQUARE_MAP + ((SQUARE_MAP + 1) / 2);
		player->py = y * SQUARE_MAP + ((SQUARE_MAP + 1) / 2);
		player->pdx = cos(player->pa);
		player->pdy = sin(player->pa);
		return (1);
	}
	return (0);
}

static int	init_player_position(char direction, t_player *player, int x, int y)
{
	if (direction == 'N')
	{
		player->pa = -(PI / 2);
		player->px = x * SQUARE_MAP + ((SQUARE_MAP + 1) / 2);
		player->py = y * SQUARE_MAP + ((SQUARE_MAP + 1) / 2);
		player->pdx = cos(player->pa);
		player->pdy = sin(player->pa);
		return (1);
	}
	else if (direction == 'S')
	{
		player->pa = PI / 2;
		player->px = x * SQUARE_MAP + ((SQUARE_MAP + 1) / 2);
		player->py = y * SQUARE_MAP + ((SQUARE_MAP + 1) / 2);
		player->pdx = cos(player->pa);
		player->pdy = sin(player->pa);
		return (1);
	}
	else
		return (init_player_position_follow(direction, player, x, y));
}

static int	init_player_x_y_max(char **map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
		y++;
	player->x_max = malloc(sizeof(int) * y);
	if (!player->x_max)
		return (1);
	player->y_max = y;
	y--;
	while (y >= 0)
	{
		x = 0;
		while (map[y][x])
			x++;
		player->x_max[y] = x;
		y--;
	}
	return (0);
}

t_player	*init_player(t_game *game)
{
	t_player	*player;
	int			x;
	int			y;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	if (init_player_x_y_max(game->map, player))
	{
		free(player);
		return (NULL);
	}
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (init_player_position(game->map[y][x], player, x, y))
				return (player);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	draw_player(mlx_image_t *img)
{
	int	x;
	int	y;
	int	x_max;
	int	y_max;

	x_max = (SQUARE_MAP * MAP_SIZE) + PLAYER_SIZE;
	y_max = (SQUARE_MAP * MAP_SIZE) + PLAYER_SIZE;
	y = (SQUARE_MAP * MAP_SIZE) - PLAYER_SIZE;
	while (y <= y_max)
	{
		x = (SQUARE_MAP * MAP_SIZE) - PLAYER_SIZE;
		while (x <= x_max)
		{
			mlx_put_pixel(img, x, y, YELLOW);
			x++;
		}
		y++;
	}
}
