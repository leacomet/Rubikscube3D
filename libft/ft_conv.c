/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:03:57 by ecorvisi          #+#    #+#             */
/*   Updated: 2022/11/02 17:19:33 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	char	tmp;
	int		nbr;

	nbr = nb;
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		tmp = (nb % 10) + '0';
		ft_putnbr(nb / 10);
		write (1, &tmp, 1);
	}
	if (nb <= 9)
	{
		tmp = nb + '0';
		write (1, &tmp, 1);
	}
	return (ft_count(nbr));
}

static int	ft_unsigned_count(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	count++;
	return (count);
}

int	ft_unsigned_putnbr(unsigned int nb)
{
	char			tmp;
	unsigned int	temp;
	unsigned int	nbr;

	temp = 0;
	nbr = nb;
	if (nb >= 10)
	{
		temp = nb % 10;
		tmp = temp + '0';
		ft_unsigned_putnbr(nb / 10);
		write (1, &tmp, 1);
	}
	if (nb <= 9)
	{
		tmp = nb + '0';
		write (1, &tmp, 1);
	}
	return (ft_unsigned_count(nbr));
}
