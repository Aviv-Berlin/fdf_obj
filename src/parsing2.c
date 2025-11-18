/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_color(char *str)
{
	int		result;
	char	*base;
	int		index;

	base = "0123456789ABCDEF";
	result = 0;
	while (*str != 'x' && *str != '\0')
		str++;
	if (*str == '\0')
		return (0xFFFFFF);
	while (*str)
	{
		if (*str >= 97 && *str <= 122)
			*str = *str - 32;
		index = 0;
		while (base[index])
		{
			if (*str == base[index])
				break ;
			index++;
		}
		result = (result * 16) + index;
		str++;
	}
	return (result);
}

char	*read_map_file(int fd)
{
	char	*string;
	char	*temp;
	char	*map;
	int		bytes_read;

	map = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		string = malloc(5000 + 1 * sizeof(char));
		if (string == NULL)
			return (NULL);
		bytes_read = read(fd, string, 5000);
		if (bytes_read < 0)
			return (null_free(string, map));
		string[bytes_read] = '\0';
		temp = get_strjoin(map, string);
		if (temp == NULL)
			return (null_free(string, NULL));
		null_free(string, map);
		map = temp;
	}
	return (map);
}

int	read_map_col(t_map *map, char *line, int y)
{
	int			index;
	char		**points;

	points = ft_split(line, ' ');
	if (points == NULL)
	{
		free_grid(map);
		return (-1);
	}
	index = 0;
	while (points[index])
	{
		map->grid[y][index].y = y;
		map->grid[y][index].x = index;
		map->grid[y][index].z = ft_atoi(points[index]);
		map->grid[y][index].or_y = y;
		map->grid[y][index].or_x = index;
		map->grid[y][index].or_z = map->grid[y][index].z;
		map->grid[y][index].color = read_color(points[index]);
		map->grid[y][index].or_color = map->grid[y][index].color;
		index++;
	}
	free_split_array(points);
	return (0);
}

t_map	*initialize_grid(t_map *map, char **map_lines)
{
	int	index;

	map->grid = malloc(map->high * sizeof(t_point *));
	if (map->grid == NULL)
	{
		free_split_array(map_lines);
		return (NULL);
	}
	index = 0;
	while (index < map->high)
	{
		map->grid[index] = malloc(map->wid * sizeof(t_point));
		if (map->grid[index] == NULL)
		{
			free_grid(map);
			return (NULL);
		}
		index++;
	}
	return (map);
}
