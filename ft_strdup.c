/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:39:30 by nohtou            #+#    #+#             */
/*   Updated: 2020/06/27 09:57:52 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*p;

	len = 0;
	while (*s1++)
		len++;
	s1--;
	len++;
	p = malloc(len);
	if (p == NULL)
		return (NULL);
	while (len--)
		*(p + len) = *s1--;
	return (p);
}
