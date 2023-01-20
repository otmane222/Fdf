/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:44:19 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/18 16:55:33 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	give_value(t_data *va, t_ihdatiyat matris, float *x, float *y)
{
	*x = matris.x + va->ox;
	*y = matris.y + va->oy;
}

void	give_value2(t_ihdatiyat end, t_ihdatiyat start, int *dx, int *dy)
{
	*dx = end.x - start.x;
	*dy = end.y - start.y;
}

void	rotation_x(t_ihdatiyat *start, t_ihdatiyat *end, t_data *va)
{
	float		i;
	float		j;

	i = start->y;
	j = end->y;
	start->y = (start->y * cos(va->angle_x)) - (start->z * sin(va->angle_x));
	start->z = (i * sin(va->angle_x)) + (start->z * cos(va->angle_x));
	end->y = (end->y * cos(va->angle_x)) - (end->z * sin(va->angle_x));
	end->z = (j * sin(va->angle_x)) + (end->z * cos(va->angle_x));
}

void	rotation_y(t_ihdatiyat *start, t_ihdatiyat *end, t_data *va)
{
	float	i;
	float	j;

	i = start->x;
	j = end->x;
	start->x = (start->z * sin(va->angle_y)) + (start->x * cos(va->angle_y));
	end->x = (end->z * sin(va->angle_y)) + (end->x * cos(va->angle_y));
	start->z = (start->y * cos(va->angle_y)) + (i * sin(va->angle_y));
	end->z = (end->y * cos(va->angle_y)) + (j * sin(va->angle_y));
}

int	rotation_z(t_ihdatiyat *start, t_ihdatiyat *end, t_data *va)
{
	float		i;
	float		j;

	i = start->x;
	j = end->x;
	start->x = (i * cos(va->angle_z)) - (start->y * sin(va->angle_z));
	start->y = (i * sin(va->angle_z)) + (start->y * cos(va->angle_z));
	end->x = (j * cos(va->angle_z)) - (end->y * sin(va->angle_z));
	end->y = (j * sin(va->angle_z)) + (end->y * cos(va->angle_z));
	return (0);
}
