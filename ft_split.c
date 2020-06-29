/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 00:01:20 by nohtou            #+#    #+#             */
/*   Updated: 2020/06/30 02:20:15 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int	get_substr_count(const char *s, char c)
{
	int	count;

	count = 1;
	while (*s)
		if (*s++ == c)
			count++;
	return (count);
}

static char	*cut_str(const char **s, char c)
{
	size_t	len;
	char	*sub_str;

	len = 0;
	while (*(*s + len) != c)
		len++;
	sub_str = malloc(len + 1);
	if (sub_str == NULL)
		return (NULL);
	strlcpy(sub_str, *s, len + 1);
	*s += len + 1;
	return (sub_str);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**str_list;
	int		i;

	count = get_substr_count(s, c);
	str_list = malloc(sizeof(char *) * (count + 1));
	if (*str_list == NULL)
		return (NULL);
	i = 0;
	while (i < count)
		str_list[i++] = cut_str(&s, c);
	str_list[i] = NULL;
	return (str_list);
}

/*
int main(void)
{
	char **list = ft_split("xxxayyyyyyazzzzz", 'a');
	while (*list)
		puts(*list++);
	return 0;
}
*/
