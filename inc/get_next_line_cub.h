/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_cub.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:14:34 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/09 17:52:17 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_CUB_H
# define GET_NEXT_LINE_CUB_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line_cub(int fd);
int		ft_strlen_gnl_cub(char *str);
int		ft_strchr_gnl_cub(char *s, char c);
void	*ft_calloc_gnl_cub(int nmemb, int size);
char	*ft_strjoin_gnl_cub(char *s1, char *s2, int nb_read);
#endif
