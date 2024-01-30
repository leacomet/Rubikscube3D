/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_RGB_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:53:01 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/20 14:44:32 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_order(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]) == 1)
		return (1);
	while (str[i] && ft_isdigit(str[i]) == 0 && str[i] != ',')
		i++;
	if (str[i] != ',')
		return (1);
	i++;
	if (ft_isdigit(str[i]) == 1)
		return (1);
	while (str[i] && ft_isdigit(str[i]) == 0 && str[i] != ',')
		i++;
	if (str[i] != ',')
		return (1);
	i++;
	if (ft_isdigit(str[i]) == 1)
		return (1);
	return (0);
}

int	strlen_color(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]) == 0 && str[i] != ',')
		i++;
	return (i);
}

void	ft_fill_buff(char *rgb_line, int *i, char *buff)
{
	int	j;

	j = 0;
	while (rgb_line[*i] && rgb_line[*i] != ',')
	{
		buff[j] = rgb_line[*i];
		(*i)++;
		j++;
	}
}
