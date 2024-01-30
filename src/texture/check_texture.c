/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:35:16 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/20 16:32:34 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_size(t_texture *texture)
{
	if (texture->png->height == 32 && texture->png->width == 32)
		return (0);
	else
	{
		ft_putstr_fd("Error\nWrong size of png\n", 2);
		return (1);
	}
}

int	check_png(t_texture *texture)
{
	int	i;

	i = ft_strlen(texture->pathfile);
	if (i < 4)
	{
		ft_putstr_fd("Error\nWrong extension file for texture\n", 2);
		return (1);
	}
	i -= 4;
	if (ft_strncmp(".png", &texture->pathfile[i], 4) == 0)
		return (0);
	ft_putstr_fd("Error\nWrong extension file for texture\n", 2);
	return (1);
}

static int	close_texture_check(t_game *game)
{
	if (game->north->fd != -1)
		close(game->north->fd);
	if (game->south->fd != -1)
		close(game->south->fd);
	if (game->east->fd != -1)
		close(game->east->fd);
	if (game->west->fd != -1)
		close(game->west->fd);
	if (game->north->fd == -1 || game->south->fd == -1
		|| game->east->fd == -1 || game->west->fd == -1)
	{
		ft_putstr_fd("Error\nCan't open texture file\n", 2);
		return (1);
	}
	return (-1);
}

int	check_if_exist(t_game *game)
{
	game->north->fd = -1;
	game->south->fd = -1;
	game->east->fd = -1;
	game->west->fd = -1;
	game->north->fd = open(game->north->pathfile, O_RDONLY);
	game->south->fd = open(game->south->pathfile, O_RDONLY);
	game->east->fd = open(game->east->pathfile, O_RDONLY);
	game->west->fd = open(game->west->pathfile, O_RDONLY);
	if (close_texture_check(game) == 1)
		return (1);
	return (0);
}
