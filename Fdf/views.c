/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:59:08 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/19 00:24:17 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iconix(t_data *datis)
{
	datis->angle_x = 0;
	datis->angle_y = 0;
	datis->angle_z = 0;
}

void	pannix(t_data *datis)
{
	datis->angle_x = 1.5708;
	datis->angle_y = 0;
	datis->angle_z = 0;
}

void	iso_view(t_data *datis)
{
	datis->angle_x = 0.523599;
	datis->angle_y = -0.523599;
	datis->angle_z = 0.523599;
}
