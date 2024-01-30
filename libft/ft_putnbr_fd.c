/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:39:29 by ecorvisi          #+#    #+#             */
/*   Updated: 2022/10/25 17:10:29 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		mod;
	char	tmp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n >= 10)
	{
		mod = n % 10;
		tmp = mod + '0';
		ft_putnbr_fd(n / 10, fd);
		write(fd, &tmp, 1);
	}
	if (n >= 0 && n <= 9)
	{
		tmp = n + '0';
		write(fd, &tmp, 1);
	}
}
