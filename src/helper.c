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

void	free_split_array(char **split)
{
	int	index;

	index = 0;
	while (split[index] != NULL)
	{
		free (split[index]);
		index++;
	}
	free(split);
}

void	free_grid(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->high)
	{
		free(map->grid[y]);
		y++;
	}
	free(map->grid);
}

int	abs_value(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

void	apply_to_grid(t_program *data, void (*f)(t_point *, t_program *))
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map->high)
	{
		x = 0;
		while (x < data->map->wid)
		{
			f(&data->map->grid[y][x], data);
			x++;
		}
		y++;
	}
}

void	apply_to_faces(t_program *data, void (*f)(t_point *, t_program *))
{
	int index;

	index = 0;
	while (data->obj->faces_sorted[index].number != -2)
	{
		f(&data->obj->faces_sorted[index], data);
		index++;
	}
}

void	swap_ints(int *n1, int *n2)
{
	int	temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void	ft_point_obj_iter(t_list *lst, t_program *data, void (*f)(void *, t_program *))
{
	if (!lst || ! f)
		return ;
	while (lst)
	{
		f(lst->content, data);
		lst = lst->next;
	}
}
