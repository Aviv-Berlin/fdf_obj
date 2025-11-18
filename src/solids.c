/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solids.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/02/28 18:27:31 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	find_square_for_face(t_program *data, int index)
{
	data->obj->left_x = INT_MAX;
	data->obj->right_x = INT_MIN;
	data->obj->top_y = INT_MAX;
	data->obj->bottom_y = INT_MIN;
	while (data->obj->faces_sorted[index].number != -1)
	{
		if (data->obj->faces_sorted[index].des_y < data->obj->top_y)
		data->obj->top_y = data->obj->faces_sorted[index].des_y;
		if (data->obj->faces_sorted[index].des_y > data->obj->bottom_y)
			data->obj->bottom_y = data->obj->faces_sorted[index].des_y;
		if (data->obj->faces_sorted[index].des_x < data->obj->left_x)
			data->obj->left_x = data->obj->faces_sorted[index].des_x;
		if (data->obj->faces_sorted[index].des_x > data->obj->right_x)
			data->obj->right_x = data->obj->faces_sorted[index].des_x;
		index++;
	}
}

void	draw_one_face(t_program *data, int index)
{
	float e;
	int inside;
	int x;
	int y;
	int start_index;
	int	color;

	cal_face_angle(data, index);
	printf("x angle = %f, y angle =%f\n", data->obj->faces_sorted[index].angle_x, data->obj->faces_sorted[index].angle_y);
	if (data->obj->faces_sorted[index].angle_y > 0 && data->obj->faces_sorted[index].angle_y < 90)
		color = 0xAA0000;
	else if (data->obj->faces_sorted[index].angle_y > 90 && data->obj->faces_sorted[index].angle_y < 180)
		color = 0x660000;
	else
		color = 0x220000;
	find_square_for_face(data, index);
	if (data->obj->left_x == -1)
		return ;
	y = data->obj->top_y;
	while(y <= data->obj->bottom_y)
	{
		x = data->obj->left_x;
		while (x <= data->obj->right_x)
		{
			inside = 1;
			start_index = index;
			while (data->obj->faces_sorted[start_index + 1].number != -1)
			{
				e = is_inside_line(x, y, data->obj->faces_sorted[start_index].des_x,
					data->obj->faces_sorted[start_index].des_y, data->obj->faces_sorted[start_index + 1].des_x,
						data->obj->faces_sorted[start_index + 1].des_y);
				if (e <= 0)
					inside = 0;
				start_index++;
			}
			e = is_inside_line(x, y, data->obj->faces_sorted[start_index].des_x, data->obj->faces_sorted[start_index].des_y,
				data->obj->faces_sorted[index].des_x, data->obj->faces_sorted[index].des_y);
			if (e <= 0)
				inside = 0;
			if (inside == 1)
//				img_pix_put(&data->img, x + data->x_offset, y + data->y_offset, brightness_shift());
				img_pix_put(&data->img, x + data->x_offset, y + data->y_offset, color);
			x++;
		}
		y++;
	}

}

float is_inside_line(int x, int y, int x1, int y1, int x2, int y2)
{
    return ((x - x2) * (y1 - y2) - (y - y2) * (x1 - x2)); 
}

void	draw_solids(t_program *data)
{
	int index;

	draw_one_face(data, 0);
	index = 1;
	while (data->obj->faces_sorted[index].number != -2)
	{
		if (data->obj->faces_sorted[index - 1].number == -1)
			draw_one_face(data, index);
		index++;
	}
}