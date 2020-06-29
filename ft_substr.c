/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 11:39:46 by nohtou            #+#    #+#             */
/*   Updated: 2020/06/29 23:37:47 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*cpy;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (s_len < start + len)
		len = s_len - start;
	cpy = malloc(len + 1);
	if (cpy == NULL)
		return (NULL);
	s += start;
	ft_strlcpy(cpy, s, len + 1);
	return (cpy);
}
