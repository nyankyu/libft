/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:08:26 by nohtou            #+#    #+#             */
/*   Updated: 2020/06/23 17:53:23 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	const unsigned char *s;
	//unsigned char sc;

	d = dst;
	s = src;
	//sc = c;
	while (n--) {
		*d++ = *s++;
		if (*(s-1) == (unsigned char)c)
			return (d);
	}
	return (NULL);
}
