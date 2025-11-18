/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:11:11 by akosloff          #+#    #+#             */
/*   Updated: 2025/02/28 18:12:45 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "../X11/keysym.h"
#include "../X11/X.h"
#include <mlx.h>
#include <math.h>
#include <stdint.h>

#define WINDOW_W 1600.00
#define WINDOW_H 900.00
#define ANGLE 0.0
#define RAD_TO_DEG (180.0 / M_PI)

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	double	or_x;
	double	or_y;
	double	or_z;
	int		color;
	int		or_color;
	double	des_x;
	double	des_y;
	int		number;
	double	angle_x;
	double	angle_y;
}	t_point;

typedef struct s_wu
{
	double	x_start;
	double	y_start;
	int		color_start;
	double	x_end;
	double	y_end;
	int		color_end;
	double	dx;
	double	dy;
	double	m;
	double	dist;
	double	index;
	double	x;
	double	y;
	int		ix;
	int		iy;
}	t_wu;

typedef struct s_vert
{
	t_point			*point;
	struct s_vert	*next;
}	t_vert;

typedef struct s_obj
{
	t_list	*vertices;
	t_list	*faces;
	t_point	*faces_sorted;
	t_list	*groups;
	int		n_faces;
	int		left_x;
	int		right_x;
	int		top_y;
	int		bottom_y;
	int		temp;
}	t_obj;

typedef struct s_map
{
	t_point	**grid;
	int		high;
	int		wid;
	int		temp;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*address;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_program
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_obj	*obj;
	t_img	img;
	t_img	menu;
	int		temp;
	char	*file_name;
	double	zoom;
	double	angle;
	int		high_y;
	int		low_y;
	int		left_x;
	int		right_x;
	int		y_offset;
	int		x_offset;
	int		temp_y_offset;
	int		temp_x_offset;
	int		high_z;
	int		low_z;
	double	center_x;
	double	center_y;
	double	center_z;
}	t_program;

//calculations.c
void		calculate_offsets(t_program *data);
void		calculate_zoom(t_program *data);
void		find_edges(t_point *point, t_program *data);
int			brightness_shift(int dyx, double dist, t_wu line);

//color_shifts.c
void		color_z(t_point *point, t_program *data);
void		color_map(t_program *data);
void		find_high_low_z(t_point *point,  t_program *data);
void		reset_color(t_point *point,  t_program *data);
int			encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
int			color_gradient(double index, double dx, t_wu line);

//cylindrical.c
void		cylindrical_projection(t_program *data);
void		calculate_cylindrical(t_point *point, t_program *data);

//events.c
int			handle_no_event(t_program *data);
int			handle_keypress(int keysym, t_program *data);
int			handle_keyrelease(int keysym, t_program *data);
int			handle_mouse_click(int button, int x, int y, t_program *data);
int			close_window(t_program *data);

//fdf.c
t_obj	*map_to_obj(t_program *data);

//helper.c
void		free_split_array(char **split);
void		free_grid(t_map *map);
int			abs_value(int n);
void		apply_to_grid(t_program *data, void (*f)(t_point *, t_program *));
void		apply_to_faces(t_program *data, void (*f)(t_point *, t_program *));
void		swap_ints(int *n1, int *n2);
void		ft_point_obj_iter(t_list *lst, t_program *data, void (*f)(void *, t_program *));

//lights.c
void	cal_face_angle(t_program *data, int index);

//parse_obj1.c
t_obj		*read_obj(t_program *data, char *file_name);
t_list		*read_vertices(char *line);
void		print_vertices(void *temp);
t_list		*read_faces(char *line);
void		print_faces(void *temp);
t_list		*find_vertices(t_list *vertices, int point);
void		link_faces(t_obj *file);
void		free_linked_v_f(t_obj *obj);


//parse_obj2.c
t_point 	*rebuild_faces(t_program *data);
int			face_points(t_list *faces, t_list *vertices, t_point *faces_sorted, int index);

//parsing.c parsing2.c
t_map		*read_map_lines(char **map_lines);
t_map		*read_map(char *map_file);
char		*read_map_file(int fd);
int			read_map_col(t_map *map, char *line, int y);
int			read_color(char *str);
t_map		*initialize_map(int high, int wid,
				char **map_lines);
char		**split_map_file(char *map_file);
t_map		*fill_grid(t_map *map, char **map_lines);
t_map		*initialize_grid(t_map *map, char **map_lines);

//point_manipulations.c
void		rotate_x(t_point *point, t_program *data);
void		rotate_y(t_point *point, t_program *data);
void		rotate_z(t_point *point, t_program *data);

//projections.c
void		create_h_lines(t_program *data);
void		create_v_lines(t_program *data);
t_wu		set_line(t_map *map, int x, int y, char h);
void		zoom(t_program *data, int key);
void		reset_model(t_program *data);
void		draw_faces(t_program *data);

//render.c
void		render(t_program *data);
void		draw_iso(t_program *data);
void		calculate_des_y(t_point *point, t_program *data);
void		calculate_des_x(t_point *point, t_program *data);
void		reset_points(t_point *point, t_program *data);
void		calculate_des_x_y_vertices(t_program *data);
void		calculate_centers(t_program *data);


//rotations.c
void		draw_z_rotation(t_program *data, int key);
void		draw_x_rotation(t_program *data, int key);
void		draw_y_rotation(t_program *data, int key);
void		translate(t_program *data, int key);

//solids.c
void		draw_solids(t_program *data);
float		is_inside_line(int x, int y, int x1, int y1, int x2, int y2);
void		draw_one_face(t_program *data, int index);

//window.c
t_program	*create_window(t_program *data);
void		draw_grid(t_map *map, t_program data);
void		hooks(t_program *data);
void		img_pix_put(t_img *img, int x, int y, int color);
void		menu(t_program *data);

//wu.c
void		draw_wu(t_wu line, t_program *data);
void		wu_h(t_wu line, t_program *data);
void		wu_v(t_wu line, t_program *data);
void		swap_start_end(t_wu *line);
double		abs_value_double(double n);





