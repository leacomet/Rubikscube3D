/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:01:24 by acomet            #+#    #+#             */
/*   Updated: 2023/10/19 17:09:11 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static uint32_t	select_png(t_game *game, t_ray ray, int i)
{
	if (ray.length_letter == 'y')
	{
		if (ray.step_y > 0)
			return (hex_to_decimal(game->south->png->pixels, i));
		else
			return (hex_to_decimal(game->north->png->pixels, i));
	}
	else
	{
		if (ray.step_x > 0)
			return (hex_to_decimal(game->east->png->pixels, i));
		else
			return (hex_to_decimal(game->west->png->pixels, i));
	}
}

uint32_t	get_pixel_color(t_game *game, t_ray ray, float length, int rgba)
{
	int	i;

	i = 0;
	if (length > 32 * HEIGHT || length < 0)
	{
		if (i < WIDTH / 2)
		{
			ray.i = WIDTH / 2;
			length = 32 * HEIGHT;
		}
		else
		{
			ray.i = WIDTH / 2 + 1;
			length = 32 * HEIGHT;
		}
	}
	i = ray.i * 32 / length * 32;
	i = (i - (i % 32) + rgba) * 4;
	return (select_png(game, ray, i));
}
