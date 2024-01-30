/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:25:13 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/20 16:33:44 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_retired_space(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = ft_strlen(str);
	if (str[i] == '\0')
		i--;
	while (i > 0 && str[i] == ' ')
		i--;
	j = 0;
	new_str = ft_calloc(i + 2, sizeof(char));
	while (j <= i)
	{
		new_str[j] = str[j];
		j++;
	}
	free(str);
	return (new_str);
}

int	load_texture_png(t_game *game)
{
	game->north->png = mlx_load_png(game->north->pathfile);
	game->south->png = mlx_load_png(game->south->pathfile);
	game->east->png = mlx_load_png(game->east->pathfile);
	game->west->png = mlx_load_png(game->west->pathfile);
	return (0);
}

int	load_texture(t_game *game)
{
	game->north->pathfile = ft_retired_space(game->north->pathfile);
	game->south->pathfile = ft_retired_space(game->south->pathfile);
	game->east->pathfile = ft_retired_space(game->east->pathfile);
	game->west->pathfile = ft_retired_space(game->west->pathfile);
	if (check_png(game->north) == 1 || check_png(game->south) == 1
		|| check_png(game->east) == 1 || check_png(game->west) == 1
		|| check_if_exist(game) == 1)
		return (1);
	load_texture_png(game);
	if (check_size(game->north) == 1 || check_size(game->south) == 1
		|| check_size(game->east) == 1 || check_size(game->west) == 1)
		return (1);
	return (0);
}
