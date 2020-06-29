/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 23:14:11 by nohtou            #+#    #+#             */
/*   Updated: 2020/06/29 23:50:16 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	char	*trimed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (is_set(*s1, set))
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	start = s1;
	while (*s1)
		s1++;
	s1--;
	while (is_set(*s1, set))
		s1--;
	trimed = malloc(s1 - start + 2);
	if (trimed == NULL)
		return (NULL);
	ft_strlcpy(trimed, start, s1 - start + 2);
	return (trimed);
}
