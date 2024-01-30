/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_impossible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:10:23 by acomet            #+#    #+#             */
/*   Updated: 2023/10/19 17:44:42 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	case_accessible(char **map, int x, int y)
{
	if (map[y][x] == '0')
		return (0);
	if (map[y][x] == 'N')
		return (0);
	if (map[y][x] == 'E')
		return (0);
	if (map[y][x] == 'S')
		return (0);
	if (map[y][x] == 'W')
		return (0);
	return (1);
}

int	movement_impossible(char **map, t_player *player, t_coor coor)
{
	t_coor	point;

	if (coor.x2 < 0 || coor.y2 < 0)
		return (0);
	point.x1 = coor.x1 / SQUARE_MAP;
	point.x2 = coor.x2 / SQUARE_MAP;
	point.y1 = coor.y1 / SQUARE_MAP;
	point.y2 = coor.y2 / SQUARE_MAP;
	if (point.y2 >= player->y_max || point.x2 >= player->x_max[point.y2])
		return (0);
	if (point.x1 != point.x2 && point.y1 != point.y2)
	{
		if (map[point.y1][point.x2] == '1' && map[point.y2][point.x1] == '1')
			return (0);
	}
	if (!case_accessible(map, point.x2, point.y2))
		return (1);
	if (!case_accessible(map, point.x2, point.y1))
		return (2);
	if (!case_accessible(map, point.x1, point.y2))
		return (3);
	return (0);
}
