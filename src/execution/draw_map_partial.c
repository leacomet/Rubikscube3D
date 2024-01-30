/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_partial.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:13:17 by acomet            #+#    #+#             */
/*   Updated: 2023/10/19 17:47:55 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_map_partial_square_axis_ordinate(t_game *game,
		t_player *player, t_coor coor)
{
	uint32_t	color;

	coor.x2 = player->px - ((int)player->px % SQUARE_MAP)
		- (SQUARE_MAP * (MAP_SIZE - 1));
	color = get_square_color(game->map, coor.x1, coor.y1, game);
	if (color != BASIC)
		draw_square_partial_grid(game->mlx, coor, color, player);
	coor.x1 = coor.x2 + (SQUARE_MAP * ((MAP_SIZE * 2) - 1));
	coor.x2 = player->px + (SQUARE_MAP * MAP_SIZE);
	color = get_square_color(game->map, coor.x1, coor.y1, game);
	if (color != BASIC)
		draw_square_partial_grid(game->mlx, coor, color, player);
}

void	draw_map_partial_square_axis_first(t_game *game, t_player *player,
		t_coor coor)
{
	int			x_max;
	uint32_t	color;

	x_max = coor.x2;
	coor.y2 = player->py - ((int)player->py % SQUARE_MAP)
		- (SQUARE_MAP * (MAP_SIZE - 1));
	if (coor.x1 % SQUARE_MAP)
	{
		draw_map_partial_square_axis_ordinate(game, player, coor);
		coor.x1 = player->px - ((int)player->px % SQUARE_MAP)
			- (SQUARE_MAP * (MAP_SIZE - 1));
		x_max = coor.x1 + (SQUARE_MAP * ((MAP_SIZE * 2) - 1));
	}
	coor.x2 = coor.x1 + SQUARE_MAP;
	while (coor.x1 < x_max)
	{
		color = get_square_color(game->map, coor.x1, coor.y1, game);
		if (color != BASIC)
			draw_square_partial_grid(game->mlx, coor, color, player);
		coor.x1 += SQUARE_MAP;
		coor.x2 += SQUARE_MAP;
	}
}

void	draw_map_partial_square_axis_last(t_game *game, t_player *player,
		t_coor coor)
{
	int			x_max;
	uint32_t	color;

	x_max = coor.x2;
	coor.y1 = player->py - ((int)player->py % SQUARE_MAP)
		+ (SQUARE_MAP * MAP_SIZE);
	if (coor.x1 % SQUARE_MAP)
	{
		draw_map_partial_square_axis_ordinate(game, player, coor);
		coor.x1 = player->px - ((int)player->px % SQUARE_MAP)
			- (SQUARE_MAP * (MAP_SIZE - 1));
		x_max = coor.x1 + (SQUARE_MAP * ((MAP_SIZE * 2) - 1));
	}
	coor.x2 = coor.x1 + SQUARE_MAP;
	while (coor.x1 < x_max)
	{
		color = get_square_color(game->map, coor.x1, coor.y1, game);
		if (color != BASIC)
			draw_square_partial_grid(game->mlx, coor, color, player);
		coor.x1 += SQUARE_MAP;
		coor.x2 += SQUARE_MAP;
	}
}

void	draw_map_partial_square_ordin_first(t_game *game, t_player *player,
		t_coor coor)
{
	int			y_max;
	uint32_t	color;

	y_max = coor.y2;
	coor.x2 = player->px - ((int)player->px % SQUARE_MAP)
		- (SQUARE_MAP * (MAP_SIZE - 1));
	coor.y2 = coor.y1 + SQUARE_MAP;
	while (coor.y1 < y_max)
	{
		color = get_square_color(game->map, coor.x1, coor.y1, game);
		if (color != BASIC)
			draw_square_partial_grid(game->mlx, coor, color, player);
		coor.y1 += SQUARE_MAP;
		coor.y2 += SQUARE_MAP;
	}
}

void	draw_map_partial_square_ordin_last(t_game *game, t_player *player,
		t_coor coor)
{
	int			y_max;
	uint32_t	color;

	y_max = coor.y2;
	coor.x1 = player->px - ((int)player->px % SQUARE_MAP)
		+ (SQUARE_MAP * MAP_SIZE);
	coor.y2 = coor.y1 + SQUARE_MAP;
	while (coor.y1 < y_max)
	{
		color = get_square_color(game->map, coor.x1, coor.y1, game);
		if (color != BASIC)
			draw_square_partial_grid(game->mlx, coor, color, player);
		coor.y1 += SQUARE_MAP;
		coor.y2 += SQUARE_MAP;
	}
}
