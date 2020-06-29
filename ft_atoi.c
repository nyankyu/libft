/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:18:37 by nohtou            #+#    #+#             */
/*   Updated: 2020/06/28 10:19:36 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdio.h>

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ');
}

static int	is_num(char c)
{
	return ('0' <= c && c <= '9');
}

static int	underflow(const char *str)
{
	char	*p;
	char	*long_min;
	size_t	len;
 
	p = (char *)str;
	long_min = "2147483648";
	len = 0;
	while (is_num(*p))
	{
		len++;
		p++;
	}
	if (len > 10)
		return (1);
	else if (len < 10)
		return (0);
	while (is_num(*str) && len--)
	{
		if (*str > *long_min)
			return (1);
		str++;
		long_min++;
	}
	return (0);
}

static int	overflow(const char *str)
{
	char	*p;
	char	*long_max;
	size_t	len;
 
	p = (char *)str;
	long_max = "2147483647";
	len = 0;
	while (is_num(*p))
	{
		len++;
		p++;
	}
	if (len > 10)
		return (1);
	else if (len < 10)
		return (0);
	while ((*str == *long_max) && len)
	{
		str++;
		long_max++;
		len--;
	}
	if (*str > *long_max)
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int		ret;
	int		neg;

	ret = 0;
	neg = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	if (!neg && overflow(str))
	{
		return ((int)LONG_MAX);
	}
	if (neg && underflow(str))
		return ((int)LONG_MIN);
	while (is_num(*str))
	{
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return (neg ? -ret : ret);
}
