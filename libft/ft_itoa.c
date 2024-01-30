/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:44:29 by ecorvisi          #+#    #+#             */
/*   Updated: 2022/10/25 17:26:26 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	divnb(long int n)
{
	size_t	divnb;

	divnb = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		divnb++;
	}
	while (n > 0)
	{
		n /= 10;
		divnb++;
	}
	return (divnb);
}

static char	*ft_conv(int n, char *number, size_t i)
{
	if (n >= 10)
	{
		number[i] = (n % 10) + '0';
		i--;
		ft_conv(n / 10, number, i);
	}
	if (n >= 0 && n <= 9 && number[i] != '-')
	{
		number[i] = n + '0';
	}
	return (number);
}

char	*ft_itoa(int n)
{
	size_t	divn;
	size_t	i;
	char	*number;

	divn = divnb(n);
	i = divn - 1;
	number = ft_calloc(divn + 1, sizeof(char));
	if (number == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		number[i] = '8';
		n *= -1;
		n /= 10;
		i--;
	}
	if (n < 0)
	{
		n *= -1;
		number[0] = '-';
	}
	number = ft_conv(n, number, i);
	number[divn] = '\0';
	return (number);
}
