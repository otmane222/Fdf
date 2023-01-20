/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:50:44 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/16 17:50:55 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*arr;
	const unsigned char	*source;
	size_t				i;

	source = src;
	arr = dst;
	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		arr[i] = source[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)(malloc(sizeof(char) * (ft_strlen(s1) + 1)));
	if (new == NULL)
		return (0);
	while (*s1)
		new[i++] = *s1++;
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	sum_of_size;
	char	*p;

	if (ft_strlen(s) < start)
		return (ft_strdup("\0"));
	sum_of_size = ft_strlen(s + start);
	j = 0;
	if (sum_of_size < len)
		len = sum_of_size;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	while (j < len)
		p[j++] = s[start++];
	p[j] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*p2;

	if (!s1 || !s2)
		return (0);
	p2 = (malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!p2)
		return (0);
	i = ft_strlen(s1);
	ft_memcpy(p2, s1, i);
	p2 = p2 + i;
	ft_memcpy(p2, s2, ft_strlen(s2)+1);
	p2 = p2 - i;
	free((char *)s1);
	return (p2);
}
