/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:25:48 by nohtou            #+#    #+#             */
/*   Updated: 2020/07/05 15:58:49 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	len;

	if (count && size > ((size_t)-1) / count)
	{
		errno = ENOMEM;
		return (NULL);
	}
	len = size * count;
	p = malloc(len);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, len);
	return (p);
}
