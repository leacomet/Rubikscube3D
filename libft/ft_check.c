/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:15:36 by ecorvisi          #+#    #+#             */
/*   Updated: 2022/11/25 19:05:20 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_letter(char letter)
{
	if (letter == 'c' || letter == 's' || letter == '%')
		return (0);
	if (letter == 'i' || letter == 'd' || letter == 'u')
		return (0);
	if (letter == 'x' || letter == 'X' || letter == 'p')
		return (0);
	return (1);
}

static int	ft_send_at_function(char letter, va_list args)
{
	int	count;

	count = 0;
	if (letter == 'c')
		count += ft_putchar(va_arg(args, int));
	if (letter == 's')
		count += ft_putstr(va_arg(args, char *));
	if (letter == 'i' || letter == 'd')
		count += ft_putnbr(va_arg(args, int));
	if (letter == 'u')
		count += ft_unsigned_putnbr(va_arg(args, unsigned int));
	if (letter == '%')
		count += ft_putchar('%');
	if (letter == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", &count);
	if (letter == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", &count);
	if (letter == 'p')
		ft_conv_p(va_arg(args, unsigned long), "0123456789abcdef", &count);
	return (count);
}

int	ft_check_str(const char *str, va_list args)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_check_letter(str[i + 1]) == 0)
		{
			count += ft_send_at_function(str[i + 1], args);
			i++;
		}
		else
		{
			count++;
			write (1, &str[i], 1);
		}
		i++;
	}
	return (count);
}
