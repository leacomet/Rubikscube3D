/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rubikscube.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:04:40 by acomet            #+#    #+#             */
/*   Updated: 2023/10/20 16:45:30 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_ceiling(t_game *game, t_coor coor, float line_h)
{
	uint32_t	color;

	if (line_h >= 0 && line_h < HEIGHT)
		coor.y1 = (HEIGHT - line_h) / 2;
	else
		coor.y1 = 0;
	coor.y2 = 0;
	color = game->ceiling->red << (8 * 3) | game->ceiling->green << (8 * 2)
		| game->ceiling->blue << 8 | 255;
	draw_line(game->mlx->mini_map, coor, color);
}

static void	draw_floor(t_game *game, t_coor coor, float line_h)
{
	uint32_t	color;

	if (line_h >= 0 && line_h < HEIGHT)
		coor.y1 = (HEIGHT + line_h) / 2;
	else
		coor.y1 = HEIGHT;
	coor.y2 = HEIGHT;
	color = game->floor->red << (8 * 3) | game->floor->green << (8 * 2)
		| game->floor->blue << 8 | 255;
	draw_line(game->mlx->mini_map, coor, color);
}

static void	draw_rubikscube_algo(t_game *game, t_ray ray, int i,
		float angl_incr)
{
	t_coor		coor;
	float		player_angle;
	int			line_h;

	player_angle = i * angl_incr;
	line_h = (SQUARE_MAP * HEIGHT) / (cos(player_angle) * ray.length_final);
	coor.x1 = i + (WIDTH / 2);
	coor.x2 = coor.x1;
	draw_ceiling(game, coor, line_h);
	draw_floor(game, coor, line_h);
	if (line_h > HEIGHT * 32)
	{
		coor.y1 = -(HEIGHT * 32) / 2;
		coor.y2 = +(HEIGHT * 32) / 2;
	}
	else
	{
		coor.y1 = (HEIGHT - line_h) / 2;
		coor.y2 = (HEIGHT + line_h) / 2;
	}
	draw_line_texture(game, coor, ray);
}

static void	draw_rubikscube_recursive(t_game *game, t_player *player,
		float angle_incr, int i)
{
	t_ray	ray;

	ray.dir_x = cos(player->pa + (i * angle_incr));
	ray.dir_y = sin(player->pa + (i * angle_incr));
	draw_rays(game, player, &ray);
	draw_rubikscube_algo(game, ray, i, angle_incr);
	if (i < WIDTH / 2)
		draw_rubikscube_recursive(game, player, angle_incr, ++i);
	if (i == WIDTH / 2)
	{
		draw_map(game, game->player);
		draw_player(game->mlx->mini_map);
	}
	if (i % 20 == 0)
		assign_coor_draw_line(game, ray);
}

void	draw_rubikscube(t_game *game, t_player *player)
{
	int		i;
	float	angle_incr;

	i = (-WIDTH) / 2;
	angle_incr = FOV * 2;
	angle_incr = angle_incr / WIDTH * PI / 180;
	draw_rubikscube_recursive(game, player, angle_incr, i);
}
