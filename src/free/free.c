/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:30:07 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/20 17:13:34 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_texture(t_texture *texture)
{
	if (texture->pathfile != NULL)
		free(texture->pathfile);
	if (texture->png != NULL)
		mlx_delete_texture(texture->png);
	free(texture);
}

void	ft_free_game(t_game *game)
{
	if (game->map != NULL)
		ft_free_tab(game->map);
	ft_free_texture(game->north);
	ft_free_texture(game->south);
	ft_free_texture(game->east);
	ft_free_texture(game->west);
	if (game->ceiling->rgb_line != NULL)
		free(game->ceiling->rgb_line);
	if (game->floor->rgb_line != NULL)
		free(game->floor->rgb_line);
	free(game->floor);
	free(game->ceiling);
	if (game->fd != -1)
		close(game->fd);
	free(game);
}
