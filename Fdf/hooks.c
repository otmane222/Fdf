/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:56:17 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/19 15:34:29 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(int keycode, t_data *datax)
{
	if (keycode == 126)
		datax->oy -= 30;
	else if (keycode == 125)
		datax->oy += 30;
	else if (keycode == 123)
		datax->ox -= 30;
	else if (keycode == 124)
		datax->ox += 30;
}

void	ft_move_x(int keycode, t_data *datax)
{
	if (keycode == 91)
		datax->angle_x += 0.05;
	else if (keycode == 84)
		datax->angle_x -= 0.05;
}

void	ft_move_yz(int keycode, t_data *datax)
{
	if (keycode == 88)
		datax->angle_y += 0.05;
	else if (keycode == 86)
		datax->angle_y -= 0.05;
	else if (keycode == 85)
		datax->angle_z += 0.05;
	else if (keycode == 83)
		datax->angle_z -= 0.05;
}

void	ft_zoom(int keycode, t_data *datix)
{
	if (keycode == 69)
	{
		datix->masafax *= 1.1;
		datix->masafay *= 1.1;
	}
	else if (keycode == 78)
	{
		datix->masafax /= 1.1;
		datix->masafay /= 1.1;
	}
}

int	closse(int keycode, t_data *datos)
{
	if (keycode == 53)
	{
		mlx_destroy_window(datos->mlx, datos->mlx_win);
		exit (0);
	}
	ft_zoom(keycode, datos);
	ft_move(keycode, datos);
	ft_move_x(keycode, datos);
	ft_move_yz(keycode, datos);
	if (keycode == 82)
		iconix(datos);
	if (keycode == 65)
		iso_view(datos);
	if (keycode == 76)
		pannix(datos);
	mlx_destroy_image(datos->mlx, datos->img);
	mlx_clear_window(datos->mlx, datos->mlx_win);
	datos->img = mlx_new_image(datos->mlx, AARD, TOOL);
	datos->addr = mlx_get_data_addr(datos->img, &datos->bits_per_pixel, \
				&datos->line_length, &datos->endian);
	full_matrix(datos);
	now_draw(datos, datos->matrix);
	return (0);
}
