/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 06:36:42 by fananrak          #+#    #+#             */
/*   Updated: 2026/04/08 13:05:53 by fananrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_char(char ch)
{
    write(1, &ch, 1);
}

void    put_str(char *str)
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
