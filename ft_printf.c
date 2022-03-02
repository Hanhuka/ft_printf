/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:48:06 by ralves-g          #+#    #+#             */
/*   Updated: 2021/12/17 16:27:45 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	has_percent(const char *str, int i, va_list ap)
{
	int	count;

	if (str[i] == '%')
		count = ft_putchar('%');
	else if (str[i] == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (str[i] == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (str[i] == 'i')
		count = ft_putnbr(va_arg(ap, int));
	else if (str[i] == 'd')
		count = ft_putnbr(va_arg(ap, int));
	else if (str[i] == 'x')
		count = int_to_hexlr(va_arg(ap, long int), 0);
	else if (str[i] == 'X')
		count = int_to_hexup(va_arg(ap, long int), 0);
	else if (str[i] == 'p')
		count = pointer_to_hex(va_arg(ap, unsigned long));
	else if (str[i] == 'u')
		count = ft_put_uns_dec(va_arg(ap, unsigned int));
	else
		count = 0;
	return (count);
}

int	print_till_percent(const char *str, int i, int nchr, va_list ap)
{
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ft_putchar(str[i]);
			nchr++;
			i++;
		}
		if (str[i] == '%')
		{
			i++;
			nchr += has_percent(str, i, ap);
		}
		if (!str[i])
			return (nchr);
		i++;
	}
	return (nchr);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		nchr;
	va_list	ap;

	nchr = 0;
	i = 0;
	va_start(ap, str);
	nchr = print_till_percent(str, i, nchr, ap);
	va_end(ap);
	return (nchr);
}
