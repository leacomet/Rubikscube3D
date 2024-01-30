/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:44:28 by acomet            #+#    #+#             */
/*   Updated: 2023/10/19 21:56:08 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	draw_cub(t_game	*game)
{
	mlx_image_t	*temp;

	temp = game->mlx->mini_map;
	game->mlx->mini_map = mlx_new_image(game->mlx->mlx, WIDTH, HEIGHT);
	if (!game->mlx->mini_map)
	{
		game->mlx->mini_map = temp;
		return (1);
	}
	draw_rubikscube(game, game->player);
	if (mlx_image_to_window(game->mlx->mlx, game->mlx->mini_map, 0, 0))
	{
		mlx_delete_image(game->mlx->mlx, game->mlx->mini_map);
		game->mlx->mini_map = temp;
		return (1);
	}
	mlx_delete_image(game->mlx->mlx, temp);
	return (0);
}
