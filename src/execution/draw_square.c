/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:49:36 by acomet            #+#    #+#             */
/*   Updated: 2023/10/17 01:23:42 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_square_partial_grid(t_mlx *mlx, t_coor coor, uint32_t color,
		t_player *player)
{
	int	temp;

	coor.x1 += (SQUARE_MAP * MAP_SIZE) - player->px;
	coor.x2 += (SQUARE_MAP * MAP_SIZE) - player->px;
	coor.y1 += (SQUARE_MAP * MAP_SIZE) - player->py;
	coor.y2 += (SQUARE_MAP * MAP_SIZE) - player->py;
	temp = coor.y1;
	while (coor.x1 < coor.x2)
	{
		coor.y1 = temp;
		while (coor.y1 < coor.y2)
		{
			mlx_put_pixel(mlx->mini_map, coor.x1, coor.y1, color);
			coor.y1++;
		}
		coor.x1++;
	}
}

void	draw_square_grid(t_game *game, int x, int y, uint32_t color)
{
	int	x_max;
	int	y_max;
	int	temp;

	x += (SQUARE_MAP * MAP_SIZE) - game->player->px;
	y += (SQUARE_MAP * MAP_SIZE) - game->player->py;
	x_max = x + SQUARE_MAP;
	y_max = y + SQUARE_MAP;
	temp = y;
	while (x < x_max)
	{
		y = temp;
		while (y < y_max)
		{
			mlx_put_pixel(game->mlx->mini_map, x, y, color);
			y++;
		}
		x++;
	}
}
