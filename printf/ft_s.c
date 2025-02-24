/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:16:48 by asadkaou          #+#    #+#             */
/*   Updated: 2025/01/12 19:26:35 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return (0);
	if (s == NULL)
		return (write(fd, "(null)", 6));
	while (s[i] != '\0')
		write(fd, &s[i++], 1);
	return (i);
}
