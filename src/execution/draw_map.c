/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:26:42 by acomet            #+#    #+#             */
/*   Updated: 2023/10/20 17:07:11 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

uint32_t	get_square_color(char **map, int x, int y, t_game *game)
{
	int	x_square;
	int	y_square;

	y_square = y / SQUARE_MAP;
	x_square = x / SQUARE_MAP;
	if (y < 0 || x < 0 || y_square >= game->player->y_max
		|| x_square >= game->player->x_max[y_square])
		return (BASIC);
	if (map[y_square][x_square] == '0')
		return (BLACK);
	if (map[y_square][x_square] == '1')
		return (WHITE);
	else if (map[y_square][x_square] == 'N' || map[y_square][x_square] == 'S'
			|| map[y_square][x_square] == 'E' || map[y_square][x_square] == 'W')
		return (BLACK);
	return (BASIC);
}

static void	draw_map_check_partial(t_game *game, t_player *player, t_coor *coor)
{
	if (coor->y1 % SQUARE_MAP)
	{
		draw_map_partial_square_axis_first(game, player, *coor);
		draw_map_partial_square_axis_last(game, player, *coor);
		coor->y1 = player->py - ((int)player->py % SQUARE_MAP)
			- (SQUARE_MAP * (MAP_SIZE - 1));
		coor->y2 = coor->y1 + (SQUARE_MAP * ((MAP_SIZE * 2) - 1));
	}
	if (coor->x1 % SQUARE_MAP)
	{
		draw_map_partial_square_ordin_first(game, player, *coor);
		draw_map_partial_square_ordin_last(game, player, *coor);
		coor->x1 = player->px - ((int)player->px % SQUARE_MAP)
			- (SQUARE_MAP * (MAP_SIZE - 1));
		coor->x2 = coor->x1 + (SQUARE_MAP * ((MAP_SIZE * 2) - 1));
	}
}

void	draw_map(t_game *game, t_player *player)
{
	t_coor		coor;
	uint32_t	color;
	int			temp;

	coor.x1 = player->px - (SQUARE_MAP * MAP_SIZE);
	coor.x2 = player->px + (SQUARE_MAP * MAP_SIZE);
	coor.y1 = player->py - (SQUARE_MAP * MAP_SIZE);
	coor.y2 = player->py + (SQUARE_MAP * MAP_SIZE);
	draw_map_check_partial(game, player, &coor);
	temp = coor.x1;
	while (coor.y1 < coor.y2)
	{
		coor.x1 = temp;
		while (coor.x1 < coor.x2)
		{
			color = get_square_color(game->map, coor.x1, coor.y1, game);
			if (color != BASIC)
				draw_square_grid(game, coor.x1, coor.y1, color);
			coor.x1 += SQUARE_MAP;
		}
		coor.y1 += SQUARE_MAP;
	}
}
