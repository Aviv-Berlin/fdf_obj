/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shifts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_z(t_point *point, t_program *data)
{
	t_wu	temp;

	if (point->or_z == 0)
		return ;
	if (point->or_z < data->high_z / 2)
	{
		temp.color_start = 0x008080;
		temp.color_end = 0x0000FF;
	}
	if (point->or_z < 0)
	{
		temp.color_start = 0xFFFF00;
		temp.color_end = 0xFFFFFF;
	}
	else
	{
		temp.color_start = 0x00FFFF;
		temp.color_end = 0xFF0000;
	}
	point->color = color_gradient(point->or_z, data->high_z, temp);
}

void	color_map(t_program *data)
{
	static char	state;

	if (data->map)
	{
		if (state == 0)
		{
			state = 1;
			data->low_z = INT_MAX;
			data->high_z = INT_MIN;
			apply_to_grid(data, find_high_low_z);
			apply_to_grid(data, color_z);
			render(data);
		}
		else
		{
			state = 0;
			apply_to_grid(data, reset_color);
			render(data);
		}
	}
	else
		mlx_string_put(data->mlx, data->win, WINDOW_W / 2.4, WINDOW_H / 2, 0xBBBB00, "color map is not supported for obj files");

}

void	reset_color(t_point *point, t_program *data)
{
	point->color = point->or_color;
	data->temp = 1;
}

void	find_high_low_z(t_point *point, t_program *data)
{
	if (point->or_z < data->low_z)
		data->low_z = point->or_z;
	if (point->or_z > data->high_z)
		data->high_z = point->or_z;
}

int	color_gradient(double index, double dx, t_wu line)
{
	double				gradient;
	unsigned char		blue0;
	unsigned char		green0;
	unsigned char		red0;

	if (dx == 0)
		return (line.color_start);
	else if (index == dx)
		return (line.color_end);
	else
		gradient = index / dx;
	blue0 = line.color_start & 0xFF;
	green0 = (line.color_start >> 8) & 0xFF;
	red0 = (line.color_start >> 16) & 0xFF;
	blue0 = (unsigned char)((1.0 - gradient) * blue0 + gradient
			* (line.color_end & 0xFF));
	green0 = (unsigned char)((1.0 - gradient) * green0 + gradient
			* ((line.color_end >> 8) & 0xFF));
	red0 = (unsigned char)((1.0 - gradient) * red0 + gradient
			* ((line.color_end >> 16) & 0xFF));
	return ((red0 << 16) | (green0 << 8) | blue0);
}
