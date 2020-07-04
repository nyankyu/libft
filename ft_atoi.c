/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:18:37 by nohtou            #+#    #+#             */
/*   Updated: 2020/07/05 03:25:45 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <errno.h>
#include "libft.h"

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ');
}

static int	overflow(long n, char digit)
{
	if (n > LONG_MAX / 10)
	{
		errno = ERANGE;
		return (1);
	}
	if (n == LONG_MAX / 10)
		if (n * 10 > LONG_MAX - (digit - '0'))
		{
			errno = ERANGE;
			return (1);
		}
	return (0);
}

static int	underflow(long n, char digit)
{
	if (n > -(LONG_MIN / 10))
	{
		errno = ERANGE;
		return (1);
	}
	if (n == -(LONG_MIN / 10))
		if (n * 10 > LONG_MIN - (digit - '0'))
		{
			errno = ERANGE;
			return (1);
		}
	return (0);
}

int			ft_atoi(const char *str)
{
	long	ret;
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
	while (ft_isdigit(*str))
	{
		if (neg && underflow(ret, *str))
			return ((int)LONG_MIN);
		if (!neg && overflow(ret, *str))
			return ((int)LONG_MAX);
		ret = ret * 10 + (*str++ - '0');
	}
	return (neg ? -ret : ret);
}
