/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:09:47 by acomet            #+#    #+#             */
/*   Updated: 2023/10/20 16:41:19 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_line(mlx_image_t *img, t_coor coor, uint32_t color)
{
	float	x;
	float	y;
	float	dy;
	float	length;

	if (abs(coor.x2 - coor.x1) >= abs(coor.y2 - coor.y1))
		length = abs(coor.x2 - coor.x1);
	else
		length = abs(coor.y2 - coor.y1);
	dy = (coor.y2 - coor.y1) / length;
	x = coor.x1;
	y = coor.y1;
	while (length)
	{
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			mlx_put_pixel(img, x + 0.5, y + 0.5, color);
		y += dy;
		length--;
	}
}

void	draw_line_ray(mlx_image_t *img, t_coor coor, uint32_t color)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	length;

	if (abs(coor.x2 - coor.x1) >= abs(coor.y2 - coor.y1))
		length = abs(coor.x2 - coor.x1);
	else
		length = abs(coor.y2 - coor.y1);
	dx = (coor.x2 - coor.x1) / length;
	dy = (coor.y2 - coor.y1) / length;
	x = coor.x1;
	y = coor.y1;
	while (length)
	{
		if (x >= 0 && x < SQUARE_MAP * MAP_SIZE * 2
			&& y >= 0 && y < SQUARE_MAP * MAP_SIZE * 2)
			mlx_put_pixel(img, x + 0.5, y + 0.5, color);
		x += dx;
		y += dy;
		length--;
	}
}

static float	get_x_texture_coordinate(t_game *game, t_ray ray)
{
	float	rgba;

	if (ray.length_letter == 'x')
	{
		rgba = game->player->py + (ray.length_final * ray.dir_y);
		rgba = (int)(rgba * 32 / SQUARE_MAP) % 32;
		if (ray.step_x < 0)
			rgba = 32 - rgba - 1;
	}
	else
	{
		rgba = game->player->px + (ray.length_final * ray.dir_x);
		rgba = (int)(rgba * 32 / SQUARE_MAP) % 32;
		if (ray.step_y > 0)
			rgba = 32 - rgba - 1;
	}
	return (rgba);
}

static int	get_texture_length(t_coor coor)
{
	int	length;

	if (abs(coor.x2 - coor.x1) >= abs(coor.y2 - coor.y1))
		length = abs(coor.x2 - coor.x1);
	else
		length = abs(coor.y2 - coor.y1);
	return (length);
}

void	draw_line_texture(t_game *game, t_coor coor, t_ray ray)
{
	int			length;
	uint32_t	color;
	float		rgba;

	rgba = get_x_texture_coordinate(game, ray);
	length = get_texture_length(coor);
	ray.i = 0;
	if (coor.y1 < 0)
	{
		ray.i -= coor.y1;
		coor.y1 = 0;
	}
	if (coor.y2 > HEIGHT)
		coor.y2 = HEIGHT;
	while (coor.y1 < coor.y2)
	{
		if (coor.x1 >= 0 && coor.x1 < WIDTH && coor.y1 >= 0 && coor.y1 < HEIGHT)
		{
			color = get_pixel_color(game, ray, length, rgba);
			mlx_put_pixel(game->mlx->mini_map, coor.x1, coor.y1, color);
		}
		coor.y1++;
		ray.i++;
	}
}
