/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:45:40 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/20 15:58:36 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_char(t_data *data, int fd)
{
	char	*buffer;
	int		i;

	buffer = get_next_line(fd);
	if (!buffer)
		return ;
	if (!data->saver)
		data->saver = ft_strdup("");
	data->saver = ft_strjoin(data->saver, buffer);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == ' ' && buffer[i + 1] != '\n')
		{
			data->width += 1;
			while (buffer[i] && buffer[i] == ' ')
				i++;
		}
		i++;
	}
	free(buffer);
	buffer = NULL;
}

void	get_width(t_data *infos, int fd)
{
	int		i;
	char	*suu;

	i = 0;
	while (1)
	{
		suu = get_next_line(fd);
		if (!suu)
			return ;
		if (suu)
			infos->saver = ft_strjoin(infos->saver, suu);
		free(suu);
		suu = NULL;
		infos->height += 1;
	}
}

size_t	ft_count_strings(char const *str, char c)
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	check_name(char *str)
{
	int		i;
	int		j;
	char	test[5];

	i = 0;
	test[0] = '.';
	test[1] = 'f';
	test[2] = 'd';
	test[3] = 'f';
	test[4] = '\0';
	while (str[i])
		i++;
	if (i <= 4)
		return (0);
	j = i - 4;
	i = 0;
	while (str[j])
	{
		if (str[j] != test[i])
			return (0);
		j++;
		i++;
	}
	return (1);
}
