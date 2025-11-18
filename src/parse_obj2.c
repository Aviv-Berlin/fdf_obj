/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point *rebuild_faces(t_program *data)
{
	t_point	*faces_sorted;
	t_list	*faces;
	int		n_faces;
	int		index;
	int		total_vertices;

	n_faces = ft_lstsize(data->obj->faces);
	data->obj->n_faces = n_faces;
	faces = data->obj->faces;
	total_vertices = 0;
	while (faces)
	{
		total_vertices += ft_lstsize(faces->content) + 1;
		faces = faces->next;
	}
	faces_sorted = malloc((total_vertices + 1) * sizeof(t_point));
	if (faces_sorted == NULL)
		return (NULL);
	faces = data->obj->faces;
	index = 0;
	while (faces)
	{
		index = face_points(faces, data->obj->vertices, faces_sorted, index);
		faces = faces->next;
	}
	faces_sorted[index].number = -2;
	return (faces_sorted);
}

int	face_points(t_list *faces, t_list *vertices, t_point *faces_sorted, int index)
{
	int			*vertex;
	t_list		*current_face;
	t_point		*temp;
	t_list		*vertices_temp;

	current_face = faces->content;
	while (current_face)
	{
		vertex = current_face->content;
		vertices_temp = vertices;
		while (vertices_temp)
		{
			temp = (t_point *)vertices_temp->content;
			if (*vertex == temp->number)
			{
				faces_sorted[index] = *temp;
				index++;
				break ;
			}
			vertices_temp = vertices_temp->next;
		}
		current_face = current_face->next;
	}
	faces_sorted[index].number = -1;
	index++;
	return (index);
}