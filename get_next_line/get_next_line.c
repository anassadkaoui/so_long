/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:45:54 by asadkaou          #+#    #+#             */
/*   Updated: 2024/12/04 19:45:56 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_found_newline(char *str_buf)
{
	int	i;

	if (!str_buf)
		return (0);
	i = 0;
	while (str_buf[i])
	{
		if (str_buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_len_to_newline(char *str_buf)
{
	int	len;

	if (!str_buf)
		return (0);
	len = 0;
	while (str_buf[len] && str_buf[len] != '\n')
		len++;
	if (str_buf[len] == '\n')
		len++;
	return (len);
}

char	*ft_get_line(char **str_buf)
{
	int		len;
	char	*line;

	if (*str_buf == NULL)
		return (NULL);
	len = ft_len_to_newline(*str_buf);
	line = malloc(len + 1);
	if (!line)
		return (free(*str_buf), *str_buf = NULL, NULL);
	ft_strlcpy(line, *str_buf, len + 1);
	return (line);
}

char	*ft_read_join(char **str_buff, int fd)
{
	int		bytes_read;
	char	*buf;
	char	*temp;

	while (ft_found_newline(*str_buff) == 0)
	{
		buf = (char *)malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
		if (!buf)
			return (free(*str_buff), *str_buff = NULL, NULL);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(*str_buff), *str_buff = NULL, free(buf), NULL);
		buf[bytes_read] = '\0';
		temp = *str_buff;
		*str_buff = ft_strjoined(*str_buff, buf);
		free(temp);
		free(buf);
		if (bytes_read == 0)
			break ;
	}
	return (*str_buff);
}

char	*get_next_line(int fd)
{
	static char	*str_buf;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_buf = ft_read_join(&str_buf, fd);
	if (!str_buf || !*str_buf)
		return (free(str_buf), str_buf = NULL, NULL);
	line = ft_get_line(&str_buf);
	if (!line)
		return (free(str_buf), str_buf = NULL, NULL);
	temp = str_buf;
	str_buf = ft_strdup(str_buf + ft_len_to_newline(str_buf));
	free(temp);
	return (line);
}
