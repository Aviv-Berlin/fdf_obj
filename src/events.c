/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(t_program *data)
{
	data->temp = 1;
	return (0);
}

int	handle_mouse_click(int button, int x, int y, t_program *data)
{
	if (0 && x == 351 && y == 36529440)
		close_window(data);
	data->temp = button;
	return (0);
}

int	handle_keypress(int keysym, t_program *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	if (keysym == 120 || keysym == 115)
		draw_x_rotation(data, keysym);
	if (keysym == 99 || keysym == 100)
		draw_y_rotation(data, keysym);
	if (keysym == 122 || keysym == 97)
		draw_z_rotation(data, keysym);
	if (keysym == 61 || keysym == 45)
		zoom(data, keysym);
	if (keysym == 114)
		reset_model(data);
	if (keysym == 113)
		color_map(data);
	if (keysym >= 65361 && keysym <= 65364)
		translate(data, keysym);
	if (keysym == 112)
		cylindrical_projection(data);
	return (0);
}

int	close_window(t_program *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_display(data->mlx);
	if (data->map)
	{
		free_grid(data->map);
		free(data->map);
	}
	else
	{
		free(data->obj->faces_sorted);
		free(data->obj);
	}
	free(data->mlx);
	free(data);
	exit(0);
}
