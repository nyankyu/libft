/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:47:10 by nohtou            #+#    #+#             */
/*   Updated: 2020/07/14 22:30:12 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t slen;
	size_t cpy_size;

	if (dst == NULL || src == NULL)
		return (0);
	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	cpy_size = slen > dstsize - 1 ? dstsize - 1 : slen;
	ft_memcpy(dst, src, cpy_size);
	dst[cpy_size] = '\0';
	return (slen);
}
