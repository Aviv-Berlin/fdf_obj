/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:47:31 by akosloff          #+#    #+#             */
/*   Updated: 2025/02/28 18:12:24 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <math.h>
#include <stdio.h>


void	cal_face_angle(t_program *data, int index)
{
	double	v1x;
	double	v1y;
	double	v1z;
	double	v2x;
	double	v2y;
	double	v2z;
	double	nx;
	double	ny;
	double	nz;
	double	N_magnitude;
	double 	angle_x;
	double	angle_y;
	
	v1x = data->obj->faces_sorted[index + 1].x - data->obj->faces_sorted[index].x;
	v1y = data->obj->faces_sorted[index + 1].y - data->obj->faces_sorted[index].y;
	v1z = data->obj->faces_sorted[index + 1].z - data->obj->faces_sorted[index].z;
	v2x = data->obj->faces_sorted[index + 2].x - data->obj->faces_sorted[index].x;
	v2y = data->obj->faces_sorted[index + 2].y - data->obj->faces_sorted[index].y;
	v2z = data->obj->faces_sorted[index + 2].z - data->obj->faces_sorted[index].z;

	nx = (v1y * v2z) - (v1z * v2y);
	ny = (v1z * v2x) - (v1x * v2z);
	nz = (v1x * v2y) - (v1y * v2x);

	N_magnitude = sqrt(nx * nx + ny * ny + nz * nz);
	data->obj->faces_sorted[index].angle_x = (acos(nx / N_magnitude)) * (180.0 / 3.14159265358);
	data->obj->faces_sorted[index].angle_y = (acos(ny / N_magnitude)) * (180.0 / 3.14159265358);
}

