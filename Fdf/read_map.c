/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:11:37 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/19 02:23:24 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	allocate_matrix(t_data *dataa)
{
	int		i;

	dataa->matrix = (t_ihdatiyat **)malloc(sizeof(t_ihdatiyat) \
	* dataa->height + 1);
	if (!dataa->matrix)
		return ;
	i = 0;
	while (i <= dataa->height)
	{
		dataa->matrix[i] = (t_ihdatiyat *)malloc(sizeof(t_ihdatiyat) \
		* dataa->width + 1);
		if (!dataa->matrix[i])
			return ;
		i++;
	}
}

void	full_matrix_z(t_data *infoz)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < infoz->height && infoz->saver[k])
	{
		j = 0;
		while (j < infoz->width && infoz->saver[k])
		{
			infoz->matrix[i][j].color = 0xFFFFFF;
			infoz->matrix[i][j].z = ft_atoi(&(infoz->saver[k]));
			if (infoz->matrix[i][j].z > 0)
				infoz->matrix[i][j].color = 0xF00000;
			k++;
			while (infoz->saver[k] && infoz->saver[k] != ' ' && \
			infoz->saver[k] != '\n' && infoz->saver[k + 1] != '-')
					k++;
			k++;
			j++;
		}
		i++;
	}
}

void	ft_empty(t_data *datas)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < datas->height)
	{
		j = 0;
		while (j < datas->width)
		{
			datas->matrix[i][j].y = 0;
			datas->matrix[i][j].x = 0;
			j++;
		}
		i++;
	}
}

void	full_matrix(t_data *datas)
{
	int		i;
	int		j;
	float	x;
	float	y;

	ft_empty(datas);
	i = 0;
	j = 0;
	y = -(datas->height * datas->masafax) / 2;
	while (i < datas->height)
	{
		j = 0;
		x = -(datas->width * datas->masafax) / 2;
		while (j < datas->width)
		{
			datas->matrix[i][j].x = x;
			datas->matrix[i][j].y = y;
			x = x + datas->masafax;
			j++;
		}
		y = y + datas->masafay;
		i++;
	}
	full_matrix_z(datas);
}

void	read_file(t_data *info, char *filename)
{
	int		i;
	int		fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	get_char(info, fd);
	get_width(info, fd);
	allocate_matrix(info);
	full_matrix(info);
}
