/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_point *point, t_program *data)
{
	double	y;
	double	z;

	y = point->y - data->center_y;
	z = point->z - data->center_z;
	point->y = y * cos(data->angle) - z * sin(data->angle);
	point->z = y * sin(data->angle) + z * cos(data->angle);
	point->y += data->center_y;
	point->z += data->center_z;
}

void	rotate_y(t_point *point, t_program *data)
{
	double	x;
	double	z;

	x = point->x - data->center_x;
	z = point->z - data->center_z;
	point->x = x * cos(data->angle) + z * sin(data->angle);
	point->z = -x * sin(data->angle) + z * cos(data->angle);
	point->x += data->center_x;
	point->z += data->center_z;
}

void	rotate_z(t_point *point, t_program *data)
{
	double	x;
	double	y;

	x = point->x - data->center_x;
	y = point->y - data->center_y;
	point->x = x * cos(data->angle) - y * sin(data->angle);
	point->y = x * sin(data->angle) + y * cos(data->angle);
	point->x += data->center_x;
	point->y += data->center_y;
}
