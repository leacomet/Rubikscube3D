/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:05:28 by acomet            #+#    #+#             */
/*   Updated: 2023/10/20 17:12:17 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	initialize_window_begininh_follow(t_game *game)
{
	if (mlx_image_to_window(game->mlx->mlx, game->mlx->mini_map, 0, 0) < 0)
	{
		ft_putstr_fd("mlx image window error\n", 2);
		free(game->mlx);
		mlx_terminate(game->mlx->mlx);
		mlx_delete_image(game->mlx->mlx, game->mlx->mini_map);
		return (1);
	}
	game->player = init_player(game);
	if (!game->player)
	{
		ft_putstr_fd("game player init error\n", 2);
		free(game->mlx);
		mlx_terminate(game->mlx->mlx);
		mlx_delete_image(game->mlx->mlx, game->mlx->mini_map);
		mlx_close_window(game->mlx->mlx);
		return (1);
	}
	return (0);
}

static int	initialize_window_begining(t_game *game)
{
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx)
		return (1);
	game->mlx->mlx = mlx_init(WIDTH, HEIGHT, "Rubikscube3D", false);
	if (!game->mlx->mlx)
	{
		ft_putstr_fd("mlx error init\n", 2);
		free(game->mlx);
		return (1);
	}
	game->mlx->mini_map = mlx_new_image(game->mlx->mlx, WIDTH, HEIGHT);
	if (!game->mlx->mini_map)
	{
		ft_putstr_fd("mlx image image error\n", 2);
		free(game->mlx);
		mlx_terminate(game->mlx->mlx);
		return (1);
	}
	return (initialize_window_begininh_follow(game));
}

int	execution(t_game *game)
{
	if (initialize_window_begining(game))
		return (1);
	draw_cub(game);
	mlx_loop_hook(game->mlx->mlx, cub_hook, game);
	mlx_loop(game->mlx->mlx);
	mlx_delete_image(game->mlx->mlx, game->mlx->mini_map);
	mlx_terminate(game->mlx->mlx);
	free(game->mlx);
	free(game->player->x_max);
	free(game->player);
	return (0);
}
