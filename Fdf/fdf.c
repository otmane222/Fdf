/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:26:33 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/20 16:10:11 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initial(t_data *data)
{
	data->masafax = 20;
	data->masafay = 20;
	data->angle_x = 0.523599;
	data->angle_y = -0.523599;
	data->angle_z = 0.523599;
	data->angle_iso = 0.52;
	data->height = 1;
	data->width = 1;
	data->ox = 900;
	data->oy = 450;
	data->color = 0xFFFFFF;
	data->flag = 0;
}

void	dda_draw_line(t_ihdatiyat start, t_ihdatiyat end, t_data *store)
{
	float	x;
	float	y;
	int		dx;
	int		dy;
	int		steps;

	store->i = rotation_z(&start, &end, store);
	rotation_x(&start, &end, store);
	rotation_y(&start, &end, store);
	give_value2(end, start, &dx, &dy);
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	give_value(store, start, &x, &y);
	store->xinc = dx / (float)steps;
	store->yinc = dy / (float)steps;
	while (store->i <= steps)
	{
		if ((x < AARD && x > 0) && (y < TOOL && y > 0))
			my_mlx_pixel_put(store, x, y, start.color + end.color);
		x += store->xinc;
		y += store->yinc;
		store->i++;
	}
}

void	now_draw(t_data *delta, t_ihdatiyat **matrix)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < delta->height)
	{
		x = 0;
		while (x < delta->width)
		{
			if (x < delta->width - 1)
				dda_draw_line(matrix[y][x], matrix[y][x + 1], delta);
			if (y < delta->height - 1)
				dda_draw_line(matrix[y][x], matrix[y + 1][x], delta);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(delta->mlx, delta->mlx_win, delta->img, 0, 0);
	return ;
}

int	close_win(t_data *param)
{
	mlx_destroy_window(param->mlx, param->mlx_win);
	exit (0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2 && check_name(av[1]))
	{
		data = malloc(sizeof (t_data));
		if (!data)
			return (0);
		initial(data);
		read_file(data, av[1]);
		data->mlx = mlx_init();
		data->mlx_win = mlx_new_window(data->mlx, AARD, TOOL, "3D world");
		data->img = mlx_new_image(data->mlx, AARD, TOOL);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
				&data->line_length, &data->endian);
		now_draw(data, data->matrix);
		mlx_hook(data->mlx_win, 17, 0, close_win, data);
		mlx_hook(data->mlx_win, 2, 0, closse, data);
		mlx_loop(data->mlx);
	}
	else
		return (0);
}
