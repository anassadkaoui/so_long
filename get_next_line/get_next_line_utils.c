/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:46:10 by asadkaou          #+#    #+#             */
/*   Updated: 2024/12/04 19:46:13 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*ft_filljoin(char *tofill, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		tofill[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		tofill[i] = s2[j];
		i++;
		j++;
	}
	tofill[i] = '\0';
	return (tofill);
}

char	*ft_strjoined(char *str_buff, char *buf)
{
	char	*strjn;

	if (str_buff == NULL && buf == NULL)
		return (NULL);
	if (buf == NULL)
		return (ft_strdup(str_buff));
	if (str_buff == NULL)
		return (ft_strdup(buf));
	strjn = malloc(sizeof(char) * ((ft_strlen(str_buff) + ft_strlen(buf)) + 1));
	if (strjn == NULL)
		return (NULL);
	strjn = ft_filljoin(strjn, str_buff, buf);
	return (strjn);
}

char	*ft_strdup(char *buf)
{
	size_t	size;
	char	*cpy;
	int		i;

	size = ft_strlen(buf);
	cpy = malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (buf[i])
	{
		cpy[i] = buf[i];
		i++;
	}
	cpy[size] = '\0';
	return (cpy);
}

size_t	ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	size_t			len;
	size_t			i;

	len = ft_strlen(src);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
