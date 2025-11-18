/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_y_rotation(t_program *data, int key)
{

	if (key == 99)
		data->angle = 0.01;
	if (key == 100)
		data->angle = -0.01;
	if (data->map)
		apply_to_grid(data, rotate_y);
	else
		apply_to_faces(data, rotate_y);
	data->angle = ANGLE;
	render(data);
}

void	draw_z_rotation(t_program *data, int key)
{
	if (key == 122)
		data->angle = 0.01;
	if (key == 97)
		data->angle = -0.01;
	if (data->map)
		apply_to_grid(data, rotate_z);
	else
		apply_to_faces(data, rotate_z);
	data->angle = ANGLE;
	render(data);

}

void	draw_x_rotation(t_program *data, int key)
{
	if (key == 120)
		data->angle = 0.01;
	if (key == 115)
		data->angle = -0.01;
	if (data->map)
		apply_to_grid(data, rotate_x);
	else
		apply_to_faces(data, rotate_x);
	data->angle = ANGLE;
	render(data);
}

void	translate(t_program *data, int key)
{
	if (data->left_x + data->x_offset + 20 > WINDOW_W)
		data->temp_x_offset = 0;
	if (data->right_x + data->x_offset + 20 < 0)
		data->temp_x_offset = 0;
	if (data->high_y + data->y_offset + 20 > WINDOW_H)
		data->temp_y_offset = 0;
	if (data->low_y + data->y_offset + 20 < 0)
		data->temp_y_offset = 0;
	if (key == 65363)
		data->temp_x_offset += 10;
	if (key == 65361)
		data->temp_x_offset -= 10;
	if (key == 65364)
		data->temp_y_offset += 10;
	if (key == 65362)
		data->temp_y_offset -= 10;
	render(data);
}
