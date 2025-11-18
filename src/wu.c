/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	abs_value_double(double n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

void	draw_wu(t_wu line, t_program *data)
{
	if ((line.x_start < 0 || line.x_start > WINDOW_W)
		&& (line.x_end < 0 || line.x_end > WINDOW_W))
		return ;
	if ((line.y_start < 0 || line.y_start > WINDOW_H)
		&& (line.y_end < 0 || line.y_end > WINDOW_H))
		return ;
	if (abs_value_double(line.x_start - line.x_end)
		> abs_value_double(line.y_start - line.y_end))
	{
		if (line.x_start > line.x_end)
			swap_start_end(&line);
		wu_h(line, data);
	}
	else
	{
		if (line.y_start > line.y_end)
			swap_start_end(&line);
		wu_v(line, data);
	}
}

void	wu_v(t_wu line, t_program *data)
{
	line.dx = abs_value_double(line.x_end - line.x_start);
	line.dy = abs_value_double(line.y_end - line.y_start);
	if (line.dy != 0)
		line.m = line.dx / line.dy;
	else
		line.m = 0;
	if (line.x_start > line.x_end)
		line.m = -line.m;
	line.index = 0;
	line.x = line.x_start;
	line.y = line.y_start;
	while (line.index <= line.dy)
	{
		line.ix = (int)(line.x + 0.5);
		line.iy = (int)(line.y + 0.5);
		line.dist = abs_value_double(line.ix - line.x);
		img_pix_put(&data->img, line.ix, line.iy,
			brightness_shift(line.dy, 1 - line.dist, line));
		img_pix_put(&data->img, line.ix + 1, line.iy,
			brightness_shift(line.dy, line.dist, line));
		line.y++;
		line.x += line.m;
		line.index++;
	}
}

void	wu_h(t_wu line, t_program *data)
{
	line.dx = abs_value_double(line.x_start - line.x_end);
	line.dy = abs_value_double(line.y_start - line.y_end);
	if (line.dx != 0)
		line.m = line.dy / line.dx;
	else
		line.m = 0;
	if (line.y_start > line.y_end)
		line.m = -line.m;
	line.index = 0;
	line.x = line.x_start;
	line.y = line.y_start;
	while (line.index <= line.dx)
	{
		line.ix = (int)(line.x + 0.5);
		line.iy = (int)(line.y + 0.5);
		line.dist = abs_value_double(line.iy - line.y);
		img_pix_put(&data->img, line.ix, line.iy,
			brightness_shift(line.dx, 1 - line.dist, line));
		img_pix_put(&data->img, line.ix, line.iy + 1,
			brightness_shift(line.dy, line.dist, line));
		line.x++;
		line.y += line.m;
		line.index++;
	}
}

void	swap_start_end(t_wu *line)
{
	double	temp;

	temp = line->x_start;
	line->x_start = line->x_end;
	line->x_end = temp;
	temp = line->y_start;
	line->y_start = line->y_end;
	line->y_end = temp;
	temp = line->color_start;
	line->color_start = line->color_end;
	line->color_end = (int)temp;
}
