/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:53:12 by ralves-g          #+#    #+#             */
/*   Updated: 2021/12/27 13:57:29 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <fcntl.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	num_count(long long n);
int	int_to_hexlr(unsigned int n, int counter);
int	int_to_hexup(unsigned int n, int counter);
int	pointer_to_hex(unsigned long n);
int	ft_put_uns_dec(unsigned int n);

#endif