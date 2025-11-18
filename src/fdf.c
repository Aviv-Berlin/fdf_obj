/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_program	*data;
	int			len;

	if (argc == 2)
	{
		data = malloc(sizeof(t_program));
		if (data == NULL)
			return (-1);
		len = ft_strlen(argv[1]);
		data->map = NULL;
		data->obj = NULL;
		data->file_name = argv[1];
		if (ft_strncmp(&argv[1][len - 3], "fdf", 3) == 0)
		{
			data->map = read_map(argv[1]);
			if (data->map == NULL)
			{
				free(data);
				return (-1);
			}
/* 			data->obj = map_to_obj(data);
			free_grid(data->map);
			free(data->map);
			data->map = NULL;
			if (data->obj == NULL)
			{
				free(data);
				return (-1);
			} */
		}
		else if (ft_strncmp(&argv[1][len - 3], "obj", 3) == 0)
		{
			data->obj = read_obj(data, argv[1]);
			if (data->obj == NULL)
			{
				free(data);
				return (-1);
			}
		}
		else
		{
			ft_printf("Error, unsupported file type\n");
			return (-1);
		}	
/* 		free(data->obj->faces_sorted);
		free(data->obj);
		free(data); */
		create_window(data);
	}
	return (0);
}

t_obj	*map_to_obj(t_program *data)
{
	size_t	data_size;
	size_t	index;
	t_obj	*file;
	int		x;
	int		y;

	file = malloc(sizeof(t_obj));
	if (file == NULL)
		return (NULL);
	data_size = ((data->map->high - 1) * (data->map->wid -1) * 5) + 1;
	file->faces_sorted = malloc(data_size * sizeof(t_point));
	if (file->faces_sorted == NULL)
	{
		free(file);
		return (NULL);
	}
	index = 0;
	y = 0;
	while (y < data->map->high - 1)
	{
		x = 0;
		while (x < data->map->wid - 1)
		{
			file->faces_sorted[index] = data->map->grid[y][x];
			file->faces_sorted[index + 1] = data->map->grid[y][x + 1];
			file->faces_sorted[index + 2] = data->map->grid[y + 1][x];
			file->faces_sorted[index + 3] = data->map->grid[y + 1][x + 1];
			file->faces_sorted[index + 4].number = -1;
			index += 5;
			x++;
		}
		y++;
	}
	file->faces_sorted[index].number = -2;
	return (file);
}
