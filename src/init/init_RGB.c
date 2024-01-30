/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_RGB.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:17:34 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/20 16:28:40 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_rgb_format(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] && str[i] != '\n' && is_white_space(str[i]) == 0)
	{
		if (str[i] == ',')
			j++;
		else if (ft_isdigit(str[i]) == 1)
			return (1);
		i++;
	}
	if (j > 2)
		return (1);
	while (str[i] && str[i] != '\n')
	{
		if (is_white_space(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_reco_rgb_number(char *str, int i, char *rgb, int j)
{
	int		k;
	char	*buff;

	k = 0;
	if (str[i] != ',' && (strlen_color(&str[i]) > 3
			|| strlen_color(&str[i]) == 0))
		return (1);
	buff = ft_calloc(4, sizeof(char));
	while (str[i] && str[i] != ',' && is_white_space(str[i]) == 0)
	{
		rgb[j] = str[i];
		buff[k] = str[i];
		j++;
		k++;
		i++;
	}
	if (ft_atoi(buff) > 255)
	{
		free(buff);
		return (1);
	}
	free(buff);
	return (0);
}

char	*ft_reco_rgb_2(char *str, int i)
{
	char	*rgb;
	int		j;

	j = 0;
	rgb = ft_calloc(ft_strlen_gnl(str) - i + 1, sizeof(char));
	while (str[i] && is_white_space(str[i]) == 0)
	{
		if (ft_reco_rgb_number(str, i, rgb, j) == 1)
		{
			free(rgb);
			return (NULL);
		}
		if (str[i] != '\n')
			rgb[j] = str[i];
		j++;
		if (str[i])
			i++;
	}
	return (rgb);
}

char	*ft_recover_rgb(char *str, int i)
{
	char	*buff;

	if (check_order(&str[i]) == 1)
	{
		ft_putstr_fd("Error\nInvalid format RGB\n", 2);
		return (NULL);
	}
	while (str[i] && is_white_space(str[i]) == 1)
		i++;
	if (check_rgb_format(str, i) == 1)
	{
		ft_putstr_fd("Error\nInvalid format RGB\n", 2);
		return (NULL);
	}
	buff = ft_reco_rgb_2(str, i);
	if (!buff)
	{
		ft_putstr_fd("Error\nInvalid RGB number\n", 2);
		return (NULL);
	}
	return (buff);
}

void	ft_valid_rgb(t_rgb *rgb)
{
	int		i;
	int		order;
	char	*buff;

	i = 0;
	order = 1;
	while (rgb->rgb_line[i] != '\0')
	{
		buff = ft_calloc(4, sizeof(char));
		ft_fill_buff(rgb->rgb_line, &i, buff);
		if (order == 1)
			rgb->red = ft_atoi(buff);
		else if (order == 2)
			rgb->green = ft_atoi(buff);
		else if (order == 3)
			rgb->blue = ft_atoi(buff);
		free(buff);
		order++;
		if (rgb->rgb_line[i])
			i++;
	}
}
