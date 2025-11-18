/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/01/29 08:11:25 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_obj	*read_obj(t_program *data, char *file_name)
{
	t_obj	*file;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_printf("Error opening file\n");
		return (NULL);
	}
	file = malloc(sizeof(t_obj));
	if (file == NULL)
		return (NULL);
	file->vertices = NULL;
	file->groups = NULL;
	file->faces = NULL;
	while ((line = get_next_line(fd)))
	{
		if (ft_strncmp(line, "v ", 2) == 0)
			ft_lstadd_back(&file->vertices, read_vertices(line));
		else if (ft_strncmp(line, "f", 1) == 0)
			ft_lstadd_back(&file->faces, read_faces(line));
		else
			free(line);
	}
	data->obj = file;
	data->obj->faces_sorted = rebuild_faces(data);
	free_linked_v_f(data->obj);
	if (data->obj->faces_sorted == NULL)
		return (NULL);
	return (data->obj);
}

void free_linked_v_f(t_obj *obj)
{
	t_list *faces;

	ft_lstclear(&obj->vertices, free);
	faces = obj->faces;
	while (faces)
	{
		ft_lstclear((t_list **)&faces->content, free);
		faces = faces->next;
	}
	ft_lstclear(&obj->faces, free);
}


t_list	*create_face(t_list *face, t_list *vertices)
{
	t_list	*sorted_face;
	t_point	*point;
	int		*vertex;

	sorted_face = NULL;
	while (face)
	{
		vertex = face->content;
		while (vertices)
		{
			point = (t_point *)vertices->content;
			if (*vertex == point->number)
			{
				ft_lstadd_back(&sorted_face, ft_lstnew(point));
				break ;
			}
			vertices = vertices->next;
		}
		face = face->next;
	}
	return (sorted_face);
}

/* void	link_faces(t_obj *file)
{
	t_list	*faces_sorted;
	t_list	*faces;

	faces = file->faces;
	faces_sorted = NULL;
	while (faces)
	{
		ft_lstadd_back(&faces_sorted, ft_lstnew(create_face(faces, file->vertices)));
		faces = faces->next;
	}
	file->faces_sorted = faces_sorted;
} */

void	print_faces(void *temp)
{
	t_list	*faces;
	t_list	*vertices_list;
//	int		*vertex;
	int		counter_f;
	int		counter_v;
	t_point	*point;

	faces = (t_list *)temp;
	vertices_list = NULL;
	counter_f = 0;
	while (faces)
	{
		counter_f++;
		ft_printf("\nface #%d: ", counter_f);
		if (!faces->content)
			printf("empty face\n");
		vertices_list = faces->content;
		counter_v = 0;

		while (vertices_list)
		{
			if (!vertices_list)
			{
				printf("face is empty\n");
				vertices_list = vertices_list->next;
				continue ;
			}
			counter_v++;
//			vertex = vertices_list->content;
			point = (t_point *)vertices_list->content;
			if (point)
				printf("%d, %f, %f, %f ", point->number, point->x, point->y, point->z);
			else
				printf("vertex is empty. ");
//			printf("%d", *vertex);
			point = NULL;
			vertices_list = vertices_list->next;
		}
		vertices_list = NULL;
		faces = faces->next;
	}
}

t_list	*find_vertices(t_list *vertices, int point)
{
	t_point	*temp;
	t_list	*iter;

	iter = vertices;
	while (iter != NULL)
	{
		temp = (t_point *)iter->content;
		ft_printf("find vertices number=%d\n", temp->number);
		if (temp->number == point)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}

t_list	*read_faces(char *line)
{
	char	**temp;
	int		index;
	t_list	*face;
	int		*vertex;

	temp = ft_split(line, ' ');
	if (temp == NULL)
		return (NULL);
	face = NULL;
	index = 1;
	while (temp[index])
	{
		vertex = malloc(sizeof(int));
		if (vertex == NULL)
		{
			ft_lstclear(&face, free);
			free_split_array(temp);
			free(line);
			return (NULL);
		}
		*vertex = ft_atoi(temp[index]);
		ft_lstadd_back(&face, ft_lstnew(vertex));
		index++;
	}
	free_split_array(temp);
	free(line);
	return (ft_lstnew(face));
}

t_list	*read_vertices(char *line)
{
	t_point		*point;
	char		**temp;
	static int	number;

	number++;
	temp = ft_split(line, ' ');
	if (temp == NULL)
		return (NULL);
	free(line);
	point = malloc(sizeof(t_point));
	if (point == NULL)
	{
		free_split_array(temp);
		free(line);
		return (NULL);
	}
	point->or_x = atof(temp[1]);
	point->x = point->or_x;
	point->or_y = atof(temp[3]);
	point->y = point->or_y;
	point->or_z = atof(temp[2]);
	point->z = point->or_z;
	point->color = 0x0000FF;
	point->or_color = 0x0000FF;
	point->number = number;
	free_split_array(temp);
	return (ft_lstnew(point));
}

void	print_vertices(void *temp)
{
	t_point	*point;
	point = (t_point *)temp;
	printf("vertices #%d: x=%f, y=%f, z=%f\n", point->number, point->x, point->y, point->z);
}

