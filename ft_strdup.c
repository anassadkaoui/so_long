/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:40:59 by asadkaou          #+#    #+#             */
/*   Updated: 2024/11/11 14:09:40 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_strcpy(const char *s, char *dup)
{
	while (*s != '\0')
	{
		*dup = *s;
		s++;
		dup++;
	}
	*dup = '\0';
}

char	*ft_strduup(const char *s)
{
	char	*dup;

	dup = (char *)malloc(ft_strleen(s) + 1);
	if (!dup)
		return (NULL);
	ft_strcpy(s, dup);
	return (dup);
}
