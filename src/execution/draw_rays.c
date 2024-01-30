/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:15:04 by acomet            #+#    #+#             */
/*   Updated: 2023/10/18 16:11:27 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	initialize_ray_first_variable(t_player *player, t_ray *ray)
{
	float	ray_dir_y_on_x;
	float	ray_dir_x_on_y;

	ray_dir_y_on_x = (ray->dir_y) / (ray->dir_x);
	ray_dir_x_on_y = (ray->dir_x) / (ray->dir_y);
	ray->step_length_x = sqrt(1 + ((ray_dir_y_on_x) * (ray_dir_y_on_x)));
	ray->step_length_y = sqrt(1 + ((ray_dir_x_on_y) * (ray_dir_x_on_y)));
	ray->map_check_x = player->px / SQUARE_MAP;
	ray->map_check_y = player->py / SQUARE_MAP;
	ray->end = 0;
	ray->length_final = 0;
}

static void	initialize_ray(t_player *player, t_ray *ray)
{
	initialize_ray_first_variable(player, ray);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->length_x = (player->px - (ray->map_check_x * SQUARE_MAP))
			* ray->step_length_x;
	}
	else
	{
		ray->step_x = 1;
		ray->length_x = (((ray->map_check_x + 1) * SQUARE_MAP) - player->px)
			* ray->step_length_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->length_y = (player->py - (ray->map_check_y * SQUARE_MAP))
			* ray->step_length_y;
	}
	else
	{
		ray->step_y = 1;
		ray->length_y = (((ray->map_check_y + 1) * SQUARE_MAP) - player->py)
			* ray->step_length_y;
	}
}

void	draw_rays(t_game *game, t_player *player, t_ray *ray)
{
	initialize_ray(player, ray);
	while (!ray->end && ray->length_final < 5000)
	{
		if (ray->length_x < ray->length_y)
		{
			ray->map_check_x += ray->step_x;
			ray->length_final = ray->length_x;
			ray->length_x += ray->step_length_x * SQUARE_MAP;
			ray->length_letter = 'x';
		}
		else
		{
			ray->map_check_y += ray->step_y;
			ray->length_final = ray->length_y;
			ray->length_y += ray->step_length_y * SQUARE_MAP;
			ray->length_letter = 'y';
		}
		if (game->map[ray->map_check_y][ray->map_check_x] == '1')
			ray->end = 42;
	}
}

void	assign_coor_draw_line(t_game *game, t_ray ray)
{
	t_coor	coor;

	coor.x1 = SQUARE_MAP * MAP_SIZE;
	coor.y1 = SQUARE_MAP * MAP_SIZE;
	coor.x2 = SQUARE_MAP * MAP_SIZE + (ray.dir_x * ray.length_final);
	coor.y2 = SQUARE_MAP * MAP_SIZE + (ray.dir_y * ray.length_final);
	draw_line_ray(game->mlx->mini_map, coor, GREEN);
}
