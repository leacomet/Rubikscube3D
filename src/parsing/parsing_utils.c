/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:04:37 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/20 14:50:20 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_allow(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == 'N' || c == 'W'
		|| c == 'S' || c == 'E')
		return (0);
	return (1);
}

int	check_how_many(char **map)
{
	int	i;
	int	j;
	int	boolean;

	i = 0;
	boolean = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
					|| map[i][j] == 'E')
				boolean++;
			j++;
		}
		i++;
	}
	if (boolean > 1)
		return (1);
	else
		return (0);
}

int	check_if_c_allow(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (0);
	return (1);
}

int	check_around_0(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'W'
		|| map[i][j] == 'E' || map[i][j] == 'S')
	{
		if (i <= 0 || i >= ft_strlen_tab(map) || j <= 0)
			return (1);
		if (j > ft_strlen_gnl_cub(map[i - 1])
			|| check_if_c_allow(map[i - 1][j]) == 1)
			return (1);
		if (check_if_c_allow(map[i][j - 1]) == 1)
			return (1);
		if (j < (int)ft_strlen(map[i]))
		{
			if (check_if_c_allow(map[i][j + 1]) == 1)
				return (1);
		}
		else
			return (1);
		if (!map[i + 1] || j > ft_strlen_gnl_cub(map[i + 1])
			|| check_if_c_allow(map[i + 1][j]) == 1)
			return (1);
	}
	return (0);
}

int	check_filename(char *str)
{
	int		i;
	int		j;
	char	*strr;

	j = 0;
	i = ft_strlen(str) - 1;
	strr = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	while (i >= 0)
	{
		strr[j] = str[i];
		i--;
		j++;
	}
	i = 4;
	if (strr[i] == '\0' || strr[i] == '/')
	{
		free(strr);
		return (1);
	}
	free(strr);
	return (0);
}
