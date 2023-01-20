/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:37:00 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/19 15:52:08 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_count_stringss(char const *str, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != c && j == 0)
		{
			j = 1;
			k++;
		}
		else if (str[i] == c)
		{
			j = 0;
		}
		i++;
	}
	return (k);
}

static size_t	ft_count_char(char const *s, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char	**free_all(char **s, size_t i)
{
	while (i >= 0 && s[i] != NULL)
	{
		free(s[i]);
		s[i] = NULL;
		i--;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**strs;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	strs = (char **)(malloc(sizeof(char *) * (ft_count_strings(s, c) + 1)));
	if (!strs)
		return (NULL);
	while (j < ft_count_strings(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		strs[j] = ft_substr(&s[i], 0, (ft_count_char(s, i, c)));
		if (!strs[j] && j < ft_count_strings(s, c))
			return (free_all(strs, j));
		i += ft_count_char(s, i, c);
		j++;
	}
	strs[j] = 0;
	return (strs);
}
