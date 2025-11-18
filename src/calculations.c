/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_offsets(t_program *data)
{
	data->high_y = WINDOW_H;
	data->low_y = 0;
	data->left_x = WINDOW_W;
	data->right_x = 0;
	if (data->map)
		apply_to_grid(data, find_edges);
	else
		apply_to_faces(data, find_edges);
	//		ft_point_obj_iter(data->obj->vertices, data, (void (*)(void *, t_program *))find_edges);
	data->x_offset = (WINDOW_W / 2) - ((data->left_x + data->right_x) / 2);
	data->y_offset = (WINDOW_H / 2) - ((data->high_y + data->low_y) / 2);
}

void	calculate_zoom(t_program *data)
{
	float		zoom_x;
	float		zoom_y;

	data->high_y = WINDOW_H;
	data->low_y = 0;
	data->left_x = WINDOW_W;
	data->right_x = 0;
	if (data->map)
		apply_to_grid(data, find_edges);
	else
		apply_to_faces(data, find_edges);
	zoom_x = (WINDOW_W / (data->right_x - data->left_x)) * 0.7;
	zoom_y = (WINDOW_H / (data->low_y - data->high_y) * 0.7);
	if (zoom_y < zoom_x)
		data->zoom = zoom_y;
	else
		data->zoom = zoom_x;
}

void	find_edges(t_point *point, t_program *data)
{
	if (point->des_y < data->high_y)
		data->high_y = point->des_y;
	if (point->des_y > data->low_y)
		data->low_y = point->des_y;
	if (point->des_x < data->left_x)
		data->left_x = point->des_x;
	if (point->des_x > data->right_x)
		data->right_x = point->des_x;
}

int	brightness_shift(int dyx, double dist, t_wu line)
{
	int				color;
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;

	color = color_gradient(line.index, dyx, line);
	blue = color & 255;
	green = (color >> 8) & 255;
	red = (color >> 16) & 255;
	blue = (unsigned char)blue * dist;
	green = (unsigned char)green * dist;
	red = (unsigned char)red * dist;
	return (red << 16 | green << 8 | blue);
}
