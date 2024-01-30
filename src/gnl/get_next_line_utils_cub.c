/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_cub.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:18:08 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/11 23:31:13 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_cub.h"

int	ft_strlen_gnl_cub(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr_gnl_cub(char *s, char c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}

static void	ft_bzero_gnl_cub(void *s, int n)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc_gnl_cub(int nmemb, int size)
{
	void	*buff;

	if ((nmemb > 2147483647 || size > 2147483647) || nmemb * size > 2147483647)
		return (NULL);
	buff = malloc(nmemb * size);
	if (buff == NULL)
		return (NULL);
	ft_bzero_gnl_cub(buff, nmemb * size);
	return (buff);
}

char	*ft_strjoin_gnl_cub(char *s1, char *s2, int nb_read)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_calloc_gnl_cub(ft_strlen_gnl_cub(s1) + nb_read + 1,
			sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && j < nb_read)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	return (str);
}
