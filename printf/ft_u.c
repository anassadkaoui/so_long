/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:57:19 by asadkaou          #+#    #+#             */
/*   Updated: 2025/01/12 19:26:40 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_u(unsigned int n, int fd)
{
	int		i;
	int		len;
	char	buffer[11];

	if (fd < 0)
		return (0);
	if (n == 0)
		return (write(fd, "0", 1));
	len = count_digits(n);
	buffer[len] = '\0';
	i = len - 1;
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	write(fd, buffer, len);
	return (len);
}
