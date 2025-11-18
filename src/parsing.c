/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*read_map(char *map_file)
{
	char	**map_lines;
	t_map	*map;

	map_lines = split_map_file(map_file);
	if (map_lines == NULL)
		return (NULL);
	map = read_map_lines(map_lines);
	map = fill_grid(map, map_lines);
	free_split_array(map_lines);
	return (map);
}

char	**split_map_file(char *map_file)
{
	int		fd;
	char	*org_map;
	char	**map_lines;

	fd = open(map_file, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_printf("Error opening file\n");
		return (NULL);
	}
	org_map = read_map_file(fd);
	if (org_map == NULL)
		return (NULL);
	map_lines = ft_split(org_map, '\n');
	free(org_map);
	if (map_lines == NULL)
		return (NULL);
	return (map_lines);
}

t_map	*read_map_lines(char **map_lines)
{
	int		high;
	int		wid;
	t_map	*map;
	char	**temp_line;

	temp_line = ft_split(map_lines[0], ' ');
	if (temp_line == NULL)
		return (NULL);
	wid = 0;
	while (temp_line[wid])
		wid++;
	free_split_array(temp_line);
	high = 0;
	while (map_lines[high])
		high++;
	map = initialize_map(high, wid, map_lines);
	if (map == NULL)
		return (NULL);
	return (map);
}

t_map	*fill_grid(t_map *map, char **map_lines)
{
	int	index;

	index = 0;
	while (index < map->high)
	{
		if (read_map_col(map, map_lines[index], index) == -1)
		{
			free(map);
			return (NULL);
		}
		index++;
	}
	return (map);
}

t_map	*initialize_map(int high, int wid, char **map_lines)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
	{
		free_split_array(map_lines);
		return (NULL);
	}
	map->high = high;
	map->wid = wid;
	return (initialize_grid(map, map_lines));
}
