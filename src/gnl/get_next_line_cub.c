/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_cub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:17:26 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/09 17:51:47 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_cub.h"

static char	*get_line_cub(int fd, char *stash)
{
	char	*buff;
	int		nb_read;

	buff = ft_calloc_gnl_cub(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	nb_read = 1;
	while (nb_read != 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(buff);
			return (NULL);
		}
		stash = ft_strjoin_gnl_cub(stash, buff, nb_read);
		if (ft_strchr_gnl_cub(stash, '\n') == 1)
			break ;
	}
	free (buff);
	return (stash);
}

char	*get_next_line_cub(int fd)
{
	char		*fline;
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	fline = get_line_cub(fd, line);
	if (!fline)
		return (NULL);
	if (!*fline)
	{
		free(fline);
		return (NULL);
	}
	return (fline);
}
