/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_program	*create_window(t_program *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (NULL);
	data->win = mlx_new_window(data->mlx,
			WINDOW_W, WINDOW_H, data->file_name);
	if (data->win == NULL)
		return (NULL);
	data->img.mlx_img = mlx_new_image(data->mlx, WINDOW_W, WINDOW_H);
	data->img.address = mlx_get_data_addr(data->img.mlx_img,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	draw_iso(data);
	hooks(data);
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WINDOW_W && y >= 0 && y < WINDOW_H)
	{
		pixel = img->address + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

void	hooks(t_program *data)
{
	mlx_loop_hook(data->mlx, &handle_no_event, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win, 17, 0, &close_window, data);
	mlx_loop(data->mlx);
}

void	menu(t_program *data)
{
	mlx_string_put(data->mlx, data->win, 10, 20, 0xBBBB00, "MENU");
	mlx_string_put(data->mlx, data->win, 10, 40, 0xBBBB00, "Reset: R");
	mlx_string_put(data->mlx, data->win, 10, 60, 0xBBBB00, "Zoom: + -");
	mlx_string_put(data->mlx, data->win, 10, 80, 0xBBBB00,
		"Translate: arrow keys");
	mlx_string_put(data->mlx, data->win, 10, 100, 0xBBBB00, "Z rotation: Z-A");
	mlx_string_put(data->mlx, data->win, 10, 120, 0xBBBB00, "X rotation: X-S");
	mlx_string_put(data->mlx, data->win, 10, 140, 0xBBBB00, "Y rotation: C-D");
	mlx_string_put(data->mlx, data->win, 10, 160, 0xBBBB00, "Depth Colors: Q");
	mlx_string_put(data->mlx, data->win, 10, 180, 0xBBBB00, "Cylindrical: P");
}
