/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:47:10 by nohtou            #+#    #+#             */
/*   Updated: 2020/06/27 14:18:33 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t src_len;
	size_t count;

	if (dst == NULL || src == NULL)
		return (0);
	src_len = 0;
	while (*(src + src_len))
		src_len++;
	if (dstsize == 0)
		return (src_len);
	count = 0;
	while (count + 1 < dstsize)
	{
		*dst = *src;
		if (*src == '\0')
			return (src_len);
		dst++;
		src++;
		count++;
	}
	*dst = '\0';
	return (src_len);
}
