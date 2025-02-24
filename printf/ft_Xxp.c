/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Xxp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:24:02 by hkaddour          #+#    #+#             */
/*   Updated: 2025/01/12 19:26:45 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upperxxp(unsigned long value, char convension_specifier)
{
	char		hex[16];
	int			i;
	int			total;
	char const	*hex_digits;
	int			remainder;

	remainder = 0;
	hex_digits = "0123456789abcdef";
	if (convension_specifier == 'X')
		hex_digits = "0123456789ABCDEF";
	if (value == 0)
		return (write(1, "0", 1));
	total = 0;
	i = 0;
	while (value > 0)
	{
		remainder = value % 16;
		hex[i++] = hex_digits[remainder];
		value /= 16;
	}
	i--;
	while (i >= 0)
		total += write(1, &hex[i--], 1);
	return (total);
}
