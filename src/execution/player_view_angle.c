/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view_angle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:23:38 by acomet            #+#    #+#             */
/*   Updated: 2023/10/19 17:04:18 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	decrease_angle(t_player *player)
{
	player->pa -= 0.1;
	if (player->pa < 0)
		player->pa += 2 * PI;
	player->pdx = cos(player->pa);
	player->pdy = sin(player->pa);
	return (0);
}

static int	increase_angle(t_player *player)
{
	player->pa += 0.1;
	if (player->pa > 2 * PI)
		player->pa -= 2 * PI;
	player->pdx = cos(player->pa);
	player->pdy = sin(player->pa);
	return (0);
}

int	player_view_angle(t_mlx *mlx, t_player *player)
{
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT))
		decrease_angle(player);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT))
		increase_angle(player);
	return (0);
}
