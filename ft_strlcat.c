/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 22:04:40 by nohtou            #+#    #+#             */
/*   Updated: 2020/06/25 21:31:28 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_len;
	size_t src_len;
	size_t count;
	size_t ret;

	dst_len = 0;
	while (*(dst + dst_len))
		dst_len++;
	src_len = 0;
	while (*(src + src_len))
		src_len++;
	ret = dst_len < dstsize ? dst_len + src_len : dstsize + src_len;
	count = 0;
	while (count + dst_len + 1 < dstsize)
	{
		*(dst + dst_len + count) = *(src + count);
		if (*(src + count) == '\0')
			return (ret);
		count++;
	}
	*(dst + dst_len + count) = '\0';
	return (ret);
}
