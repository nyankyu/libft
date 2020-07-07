/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:47:10 by nohtou            #+#    #+#             */
/*   Updated: 2020/07/07 22:39:55 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t slen;
	size_t dlen;
	size_t cpy_size;

	if (dst == NULL || src == NULL)
		return (0);
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dstsize == 0)
		return (slen);
	cpy_size = slen > dlen ? dlen : slen;
	cpy_size = cpy_size > dstsize - 1 ? dstsize - 1 : cpy_size;
	ft_memcpy(dst, src, cpy_size);
	dst[cpy_size] = '\0';
	return (slen);
}
