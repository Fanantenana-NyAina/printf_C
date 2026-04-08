/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 23:07:41 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/08 08:39:42 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  conversion_handling(char c, va_list arglist)
{

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
        i++;
    }
    va_end(args);
    return (countChr);
}