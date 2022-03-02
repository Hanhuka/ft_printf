/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:01:15 by ralves-g          #+#    #+#             */
/*   Updated: 2022/01/27 12:02:20 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_put_uns_dec(unsigned int n)
{
	unsigned int	cpy;

	cpy = n;
	{
		if (n > 9)
		{
			ft_put_uns_dec(n / 10);
		}
		ft_putchar('0' + n % 10);
	}
	return (num_count(cpy));
}
