/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_model(t_program *data)
{
	data->temp_x_offset = 0;
	data->temp_y_offset = 0;
	if (data->map)
		apply_to_grid(data, reset_points);
	else
		apply_to_faces(data, reset_points);
	draw_iso(data);
}

void	zoom(t_program *data, int key)
{
	if (data->zoom > 500 || data->zoom < 0.5)
	{
		data->zoom = 1;
		if (data->map)
		{
			apply_to_grid(data, calculate_des_x);
			apply_to_grid(data, calculate_des_y);
		}
		else
			calculate_des_x_y_vertices(data);		
		calculate_zoom(data);
		render(data);
		return ;
	}
	if (key == 61)
		data->zoom = data->zoom * 1.2;
	if (key == 45)
		data->zoom = data->zoom / 1.2;
	render(data);
}

void 	draw_faces(t_program *data)
{
	t_wu	line;
	int		index;

	index = 0;
	while (data->obj->faces_sorted[index].number != -2)
	{
		if (data->obj->faces_sorted[index].number != -1 && data->obj->faces_sorted[index + 1].number != -1)
		{
			line.x_start = data->obj->faces_sorted[index].des_x + data->x_offset;
			line.y_start = data->obj->faces_sorted[index].des_y + data->y_offset;
			line.color_start = data->obj->faces_sorted[index].color;
			line.x_end = data->obj->faces_sorted[index + 1].des_x + data->x_offset;
			line.y_end = data->obj->faces_sorted[index + 1].des_y + data->y_offset;
			line.color_end = data->obj->faces_sorted[index + 1].color;
			draw_wu(line, data);
		}
		index++;
	}
}

/* void	draw_faces(t_program *data)
{
	t_wu	line;
	t_list	*vertices;
	t_list	*faces;
	t_list	*current_face;
	t_point	*start;
	t_point	*end;
	int		*v_start;
	int		*v_end;

	faces = data->obj->faces;
	while (faces)
	{
		current_face = faces->content;
		if (!current_face)  // ✅ Prevent NULL dereference
		{
			faces = faces->next;
			continue;
		}
		while (current_face->next)
		{
			v_start = (int *)current_face->content;
			vertices = data->obj->vertices;
			while (vertices)
			{
				start = (t_point *)vertices->content;
				if (*v_start == start->number)
				{
					line.x_start = start->des_x + data->x_offset;
					line.y_start = start->des_y + data->y_offset;
					line.color_start = start->color;
					break;
				}
				vertices = vertices->next;
			}
			v_end = (int *)current_face->next->content;
			vertices = data->obj->vertices;
			while (vertices)
			{
				end = (t_point *)vertices->content;
				if (*v_end == end->number)
				{
					line.x_end = end->des_x + data->x_offset;
					line.y_end = end->des_y + data->y_offset;
					line.color_end = end->color;
					break;
				}
				vertices = vertices->next;
			}
			draw_wu(line, data);
			current_face = current_face->next;
		}
		faces = faces->next;
	}
} */

void	create_v_lines(t_program *data)
{
	int		y;
	int		x;
	t_wu	line;

	y = 0;
	while (y < data->map->high)
	{
		x = 0;
		while (x < data->map->wid - 1)
		{
			line.x_start = data->map->grid[y][x].des_x + data->x_offset;
			line.y_start = data->map->grid[y][x].des_y + data->y_offset;
			line.color_start = data->map->grid[y][x].color;
			line.x_end = data->map->grid[y][x + 1].des_x + data->x_offset;
			line.y_end = data->map->grid[y][x + 1].des_y + data->y_offset;
			line.color_end = data->map->grid[y][x + 1].color;
			draw_wu(line, data);
			x++;
		}
		y++;
	}
}

void	create_h_lines(t_program *data)
{
	int		y;
	int		x;
	t_wu	line;

	y = 0;
	while (y < data->map->high - 1)
	{
		x = 0;
		while (x < data->map->wid)
		{
			line.x_start = data->map->grid[y][x].des_x + data->x_offset;
			line.y_start = data->map->grid[y][x].des_y + data->y_offset;
			line.color_start = data->map->grid[y][x].color;
			line.x_end = data->map->grid[y + 1][x].des_x + data->x_offset;
			line.y_end = data->map->grid[y + 1][x].des_y + data->y_offset;
			line.color_end = data->map->grid[y + 1][x].color;
			draw_wu(line, data);
			x++;
		}
		y++;
	}
}
/* 
t_wu	set_line(t_map *map, int x, int y, char h)
{
	t_wu	line;

	line.x_start = map->grid[y][x].des_x + map->x_offset;
	line.y_start = map->grid[y][x].des_y + map->y_offset;
	line.color_start = map->grid[y][x].color;
	line.color_end = map->grid[y + 1][x].color;
	if (h == 1)
	{
		line.x_end = map->grid[y + 1][x].des_x + map->x_offset;
		line.y_end = map->grid[y + 1][x].des_y + map->y_offset;
	}
	else
	{
		line.x_end = map->grid[y][x + 1].des_x + map->x_offset;
		line.y_end = map->grid[y][x + 1].des_y + map->y_offset;
	}
	return (line);
} */
