/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanantenana <fanantenana@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 04:31:54 by fanantenana       #+#    #+#             */
/*   Updated: 2026/04/17 04:32:04 by fanantenana      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_puthex(unsigned int n, int upper)
{
    char    *base;
    int     count;

    if (upper)
        base = "0123456789ABCDEF";
    else
        base = "0123456789abcdef";
    count = 0;
    if (n >= 16)
        count += ft_puthex(n / 16, upper);
    count += ft_putchar(base[n % 16]);
    return (count);
}
