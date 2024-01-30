/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:57:26 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/07/17 19:34:03 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(int fd, char *stash)
{
	char	*buff;
	int		nb_read;

	buff = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
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
		stash = ft_strjoin_gnl(stash, buff, nb_read);
		if (ft_strchr_gnl(stash, '\n') == 1)
			break ;
	}
	free (buff);
	return (stash);
}

static char	*complete_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	line = ft_calloc_gnl(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*reset_stash(char *stash)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ft_strchr_gnl(stash, '\n'))
	{
		free(stash);
		return (NULL);
	}
	while (stash[i] != '\n' && stash[i])
		i++;
	i++;
	next_line = ft_calloc_gnl(ft_strlen_gnl(stash) - i + 1, sizeof(char));
	if (!next_line)
		return (NULL);
	while (stash[i + j])
	{
		next_line[j] = stash[i + j];
		j++;
	}
	free (stash);
	return (next_line);
}

char	*get_next_line(int fd)
{
	char	*stash;
	char	*fline;
	char	*line;

	line = NULL;
	stash = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	fline = get_line(fd, stash);
	if (!fline)
		return (NULL);
	if (!*fline)
	{
		free(fline);
		return (NULL);
	}
	line = complete_line(fline);
	stash = reset_stash(fline);
	free(stash);
	return (line);
}
