/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:31:55 by ralves-g          #+#    #+#             */
/*   Updated: 2021/12/27 13:56:51 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	num_count(long long n)
{
	int	count;

	if (n < 0)
	{
		count = 1;
		n *= -1;
	}
	else
		count = 0;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	count++;
	return (count);
}

int	ft_putnbr(int n)
{
	int	cpy;

	cpy = n;
	if (n == -2147483648)
	{
		ft_putnbr(n / 10);
		ft_putchar('8');
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr(n / 10);
		}
		ft_putchar('0' + n % 10);
	}
	if (cpy == -2147483648)
		return (11);
	else
		return (num_count(cpy));
}

int	int_to_hexlr(unsigned int n, int counter)
{
	char			*base;
	unsigned int	cpy;

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
		int_to_hexlr(n / 16, counter);
		ft_putchar(base[n % 16]);
	}
	else
		ft_putchar(base[n % 16]);
	return (counter);
}
