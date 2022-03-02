/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:35:02 by ralves-g          #+#    #+#             */
/*   Updated: 2022/01/27 12:02:32 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	int_to_hexup(unsigned int n, int counter)
{
	char			*base;
	unsigned int	cpy;

	cpy = n;
	base = "0123456789ABCDEF";
	while (cpy >= 16)
	{
		cpy /= 16;
		counter++;
	}
	counter++;
	if (n >= 16)
	{
		int_to_hexup(n / 16, counter);
		ft_putchar(base[n % 16]);
	}
	else
		ft_putchar(base[n % 16]);
	return (counter);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	else
		return (c);
}

int	num_siz_hex(unsigned long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

/*int	pointer_to_hex(unsigned long n)
{
	int		i;
	char	str[13];
	int		counter;

	if (n == 0)
	{
		return (ft_putstr("0x0"));
	}
	i = num_siz_hex(n);
	while (n != 0)
	{
		if ((n % 16) < 10)
			str[i - 1] = n % 16 + 48;
		else
			str[i - 1] = ft_tolower((n % 16) + 48 + 7);
		n /= 16;
		i--;
	}
	str[12] = '\0';
	counter = ft_putstr("0x");
	counter += ft_putstr(str);
	return (counter);
}*/

int	ptr_to_hexlr(unsigned long n, int counter)
{
	char			*base;
	unsigned long	cpy;

	cpy = n;
	base = "0123456789abcdef";
	while (cpy >= 16)
	{
		cpy /= 16;
		counter++;
	}
	counter++;
	if (n >= 16)
	{
		ptr_to_hexlr(n / 16, counter);
		ft_putchar(base[n % 16]);
	}
	else
		ft_putchar(base[n % 16]);
	return (counter);
}

int	pointer_to_hex(unsigned long n)
{
	int	counter;

	ft_putstr("0x");
	counter = ptr_to_hexlr(n, 0) + 2;
	return (counter);
}
