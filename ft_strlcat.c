/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 22:04:40 by nohtou            #+#    #+#             */
/*   Updated: 2020/06/26 02:04:34 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t ret;

	ret = 0;
	while (*dst)
	{
		dst++;
		ret++;
	}
	if (ret > dstsize)
		ret = dstsize;
	while (*src && ret + 1 < dstsize)
	{
		*dst++ = *src++;
		ret++;
	}
	*dst = '\0';
	while (*src++)
		ret++;
	return (ret);
}
