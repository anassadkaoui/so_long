/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:26:22 by asadkaou          #+#    #+#             */
/*   Updated: 2025/01/12 19:26:25 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_params(char cs, va_list args)
{
	int	char_printed;

	char_printed = 0;
	if (cs == 'X')
		char_printed += ft_upperxxp(va_arg(args, unsigned int), cs);
	else if (cs == 'x')
		char_printed += ft_upperxxp(va_arg(args, unsigned int), cs);
	else if (cs == 'p')
	{
		char_printed += ft_s("0x", 1);
		char_printed += ft_upperxxp(va_arg(args, unsigned long), cs);
	}
	else if (cs == 'd' || cs == 'i')
		char_printed += ft_id(va_arg(args, int), 1);
	else if (cs == 'u')
		char_printed += ft_u(va_arg(args, unsigned int), 1);
	else if (cs == 's')
		char_printed += ft_s(va_arg(args, char *), 1);
	else if (cs == 'c')
		char_printed += ft_c(va_arg(args, int));
	else if (cs == '%')
		char_printed += ft_c(cs);
	else
		char_printed += ft_c(cs);
	return (char_printed);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		char_printed;

	if (write(1, "", 0) == -1)
		return (-1);
	char_printed = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) == '\0')
			return (char_printed);
		if (*str == '%')
		{
			str++;
			char_printed += ft_params(*str, args);
		}
		else
			char_printed += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (char_printed);
}
