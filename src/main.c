/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:44:55 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/20 14:52:10 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nToo many argument\n", 2);
		return (1);
	}
	game = parsing(argv[1]);
	if (!game)
		return (1);
	if (execution(game) == 1)
	{
		ft_free_game(game);
		return (1);
	}
	ft_free_game(game);
	return (0);
}
