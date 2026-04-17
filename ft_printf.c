/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanantenana <fanantenana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 23:07:41 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/17 05:33:57 by fanantenana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int conversion_handling(char c, va_list args)
{
    if (c == 'c')
        return (ft_putchar(va_arg(args, int)));
    else if (c == 's')
        return (ft_putstr(va_arg(args, char *)));
    else if (c == 'd' || c == 'i')
        return (ft_putnbr(va_arg(args, int)));
    else if (c == 'u')
        return (ft_putunsigned(va_arg(args, unsigned int)));
    else if (c == 'x')
        return (ft_puthex(va_arg(args, unsigned int), 0));
    else if (c == 'X')
        return (ft_puthex(va_arg(args, unsigned int), 1));
    else if (c == 'p')
        return (ft_putpointer(va_arg(args, void *)));
    else if (c == '%')
        return (ft_putchar('%'));
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int     countChr;
    int     i;

    va_start(args, format);
    countChr = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            countChr += conversion_handling(format[i], args);
        }
        else
        {
            countChr += ft_putchar(format[i]);
        }
        i++;
    }
    va_end(args);
    return (countChr);
}
