/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:39:54 by nohtou            #+#    #+#             */
/*   Updated: 2020/06/23 17:02:46 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	const unsigned char *s;

	if (!dst && !src && n)
		return (dst);
	d = dst;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
