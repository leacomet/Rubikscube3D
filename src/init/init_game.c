/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:38:12 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/20 16:37:42 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**ft_addtab(char	**tab, char *str)
{
	int		i;
	char	**dup_tab;

	dup_tab = ft_calloc(ft_strlen_tab(tab) + 2, sizeof(char **));
	i = 0;
	while (tab[i])
	{
		dup_tab[i] = ft_strdup_cub(tab[i]);
		i++;
	}
	dup_tab[i] = ft_strdup_cub(str);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (dup_tab);
}

char	**recover_file(t_game *game, char *str)
{
	char	**split;
	char	*buffer;

	game->fd = open(str, O_RDWR);
	if (game->fd == -1)
	{
		ft_putstr_fd("Error\nProblem opening file\n", 2);
		return (NULL);
	}
	buffer = get_next_line_cub(game->fd);
	split = ft_calloc(sizeof (char **), 1);
	while (buffer)
	{
		split = ft_addtab(split, buffer);
		free(buffer);
		buffer = get_next_line_cub(game->fd);
	}
	return (split);
}

t_texture	*ft_malloc_texture(void)
{
	t_texture	*new;

	new = malloc(sizeof(t_texture));
	new->pathfile = NULL;
	new->png = NULL;
	return (new);
}

t_game	*ft_init_game(char *str)
{
	t_game	*game;
	char	**split;

	game = malloc(sizeof(t_game));
	game->north = ft_malloc_texture();
	game->south = ft_malloc_texture();
	game->east = ft_malloc_texture();
	game->west = ft_malloc_texture();
	game->floor = malloc(sizeof(t_rgb));
	game->ceiling = malloc(sizeof(t_rgb));
	game->floor->rgb_line = NULL;
	game->ceiling->rgb_line = NULL;
	game->map = NULL;
	game->fd = -1;
	split = recover_file(game, str);
	if (!split || ft_init_game_texture(game, split) == 1
		|| ft_check_if_error(game) == 1)
	{			
		ft_free_game(game);
		return (NULL);
	}
	return (game);
}
