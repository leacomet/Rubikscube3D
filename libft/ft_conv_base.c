/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:41:01 by ecorvisi          #+#    #+#             */
/*   Updated: 2022/11/03 18:47:48 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long nb, char *base, int *count)
{
	int	tmp;

	tmp = 0;
	if (nb >= 16)
		ft_putnbr_base(nb / 16, base, count);
	tmp = nb % 16;
	write(1, &base[tmp], 1);
	(*count)++;
}

static void	ft_put_p(unsigned long nb, char *base, int *count)
{
	int	tmp;

	tmp = 0;
	if (nb >= 16)
		ft_putnbr_base(nb / 16, base, count);
	tmp = nb % 16;
	write(1, &base[tmp], 1);
	(*count)++;
}

void	ft_conv_p(unsigned long nb, char *base, int *count)
{
	if (nb)
	{
		write(1, "0x", 2);
		(*count) += 2;
	}
	if (!nb)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	ft_put_p(nb, base, count);
}
