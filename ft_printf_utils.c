/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 06:36:42 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/10 08:34:07 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putchar(char ch)
{
    write(1, &ch, 1);
}

void    ft_putstr(char *str)
{
    if (!str)
        return ;
    while (*str)
    {
        write(1, *str, 1);
        str++;
    }
    return ;
}

void	ft_putnbr(int n)
{
	char	res;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, 1);
	res = (nb % 10) + '0';
	write (1, &res, 1);
}
