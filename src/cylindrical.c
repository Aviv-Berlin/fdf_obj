/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindrical.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_cylindrical(t_point *point, t_program *data)
{
	double	x;
	int		radius;

	x = point->x;
	radius = data->map->wid * 5;
	point->x = (radius + point->z * 5) * sin(x / data->map->wid * 2 * 3.14);
	point->y = point->y * data->map->high * 3;
	point->z = (radius + point->z * 1) * cos(x / data->map->wid * 2 * 3.14);
}

void	cylindrical_projection(t_program *data)
{
	static char	state;

	if (data->map)
	{
		if (state == 0)
		{
			state = 1;
			apply_to_grid(data, reset_points);
			apply_to_grid(data, calculate_cylindrical);
			data->zoom = 1;
			apply_to_grid(data, calculate_des_x);
			apply_to_grid(data, calculate_des_y);
			calculate_zoom(data);
			data->angle = 3.5;
			apply_to_grid(data, rotate_y);
			data->angle = 0.3;
			render(data);
		}
		else
		{
			reset_model(data);
			state = 0;
		}
	}
	else
		mlx_string_put(data->mlx, data->win, WINDOW_W / 2.4, WINDOW_H / 2, 0xBBBB00, "Cylindrical projection is not supported for obj files");
}
