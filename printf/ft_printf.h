/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:26:29 by asadkaou          #+#    #+#             */
/*   Updated: 2025/01/12 19:26:31 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_params(char cs, va_list args);
int	ft_upperxxp(unsigned long value, char cs);
int	ft_id(int n, int fd);
int	ft_u(unsigned int n, int fd);
int	ft_s(char *s, int fd);
int	ft_c(char s);

#endif
