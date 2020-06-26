/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:25:48 by nohtou            #+#    #+#             */
/*   Updated: 2020/06/26 18:35:06 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	len;

	len = size * count;
	p = malloc(len);
	if (p == NULL)
		return (NULL);
	while (len--)
		*(p + len) = 0;
	return (p);
}
