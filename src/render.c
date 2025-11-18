/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/02/28 18:14:37 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_program *data)
{
	if (data->map)
	{
		apply_to_grid(data, calculate_des_x);
		apply_to_grid(data, calculate_des_y);
	}
	else
		calculate_des_x_y_vertices(data);	
	calculate_centers(data);
	data->x_offset = (WINDOW_W / 2) - data->center_x;
	data->y_offset = (WINDOW_H / 2) - data->center_y;
//	calculate_offsets(data);
	data->x_offset += data->temp_x_offset;
	data->y_offset += data->temp_y_offset;
	ft_bzero(data->img.address, WINDOW_H * WINDOW_W * (data->img.bpp / 8));
	if (data->map)
	{
		create_v_lines(data);
		create_h_lines(data);
	}
	else
	{
		draw_solids(data);
		draw_faces(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	menu(data);
}

void	draw_iso(t_program *data)
{
	data->angle = ANGLE;
	data->zoom = 1;
	data->x_offset = 0;
	data->y_offset = 0;
	data->low_z = INT_MAX;
	data->high_z = INT_MIN;
	if (data->map)
	{
		apply_to_grid(data, calculate_des_x);
		apply_to_grid(data, calculate_des_y);
		apply_to_grid(data, find_high_low_z);
	}
	else
	{
		data->angle = 0;
		calculate_des_x_y_vertices(data);
		apply_to_faces(data, find_high_low_z);
	}
	calculate_zoom(data);
	render(data);
}

void	calculate_centers(t_program *data)
{
	int		index;
	int		count;
	double	temp_x;
	double	temp_y;
	double	temp_z;

	if (data->map)
	{
		calculate_offsets(data);
		data->center_x = (data->left_x + data->right_x) / 2;
		data->center_y = (data->high_y + data->low_y) / 2;
		data->center_z = (data->high_z + data->low_z) / 2;
	}
	else
	{
		index = 0;
		temp_x = 0;
		temp_y = 0;
		temp_z = 0;
		count = 0;
		while (data->obj->faces_sorted[index].number != -2)
		{
			if (data->obj->faces_sorted[index].number != -1)
			{
				temp_x += data->obj->faces_sorted[index].x;
				temp_y += data->obj->faces_sorted[index].y;
				temp_z += data->obj->faces_sorted[index].z;
				count++;
			}
			index++;
		}
		data->center_x = temp_x / count;
		data->center_y = temp_y / count;
		data->center_z = temp_z / count;
	}
}

void	calculate_des_x_y_vertices(t_program *data)
{
	int		index;

	index = 0;
	while (data->obj->faces_sorted[index].number != -2)
	{
		data->obj->faces_sorted[index].des_x = ((data->obj->faces_sorted[index].x - data->obj->faces_sorted[index].y) * cos(data->angle)) * data->zoom;
		data->obj->faces_sorted[index].des_y = ((data->obj->faces_sorted[index].x + data->obj->faces_sorted[index].y) + sin(data->angle)
				- (data->obj->faces_sorted[index].z)) * data->zoom;
		index++;
	}
}

void	calculate_des_x(t_point *point, t_program *data)
{
	point->des_x = ((point->x - point->y) * cos(data->angle)) * data->zoom;
}

void	calculate_des_y(t_point *point, t_program *data)
{
	point->des_y = ((point->x + point->y) + sin(data->angle)
			- (point->z / 4)) * data->zoom;
}

void	reset_points(t_point *point, t_program *data)
{
	point->x = point->or_x;
	point->y = point->or_y;
	point->z = point->or_z;
	point->color = point->or_color;
	data->temp = 1;
}
