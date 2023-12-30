/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:12:10 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/30 23:22:52 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./libft/libft/get_next_line.h"

# include "lib/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_map
{
	int		size_y;
	int		size_x;
	int		**map;
	char	***colmap;
	char	*line;
	int		fd;
	int		min_height;
	int		max_height;
}	t_map;

typedef struct s_wf
{
	float		x;
	float		y;
	float		x_incr;
	float		y_incr;
	float		temp_x;
	float		temp_y;
	float		max;
	int			z;
	int			z1;
	float		zoom;
	long		colour;
	int			colour_delta;
	int			dimension;
	float		incr[3];
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*matrix;
	int			shift_x;
	int			shift_y;
	float		angle;
	int			colour_flag;
}	t_wf;

void	colour_extractor(char **temp, t_map *matrix, int j);
int		count_rows(char **argv, t_map *matrix);
char	*matrix_initializer(t_map *matrix, char **argv);
t_map	*map_creation(t_map *matrix, int j, int i);
t_map	*reader(char **argv);
void	gnl_cleaner(int fd);
int		array_length_with_free(char **split_line);
int		array_length(char **split_line);
char	*ft_strdup_nl(const char *s1);
int		is_valid_num(char *str);
int		null_checker(char *str, int j, int temp);
int		atoi_checker(t_map *matrix, char **temp, int i, int j);

int		free_mtx_gnl(t_map *matrix);
int		free_mtx_map_gnl(t_map *matrix, int j);
int		free_mtx_map(t_map *matrix, int j);
int		free_if_init_fail(t_wf *frame);
void	free_array(void **arr, int length);
void	free_split(char **arr);
void	free_triple_pointer(t_map *matrix, int length);
int		free_mtx_gnl_buf(char *buffer, t_map *matrix);
int		free_mtx_map_tmp_gnl(t_map *matrix, char **temp, int j, int i);

void	ft_exit(t_wf *frame, int status);
void	move_rotate_iso_exit(mlx_key_data_t keydata, void *param);
void	zoom(double xdelta, double ydelta, void *param);
long	set_x(t_wf *frame, t_map *matrix);
long	set_y(t_wf *frame, t_map *matrix);
int		if_colours_exist(t_wf *frame);
void	synt_colmap_creation(t_wf *frame);
long	colour_to_long(t_wf *frame, t_map *matrix, int i, int j);
void	draw_wireframe(t_wf *frame, t_map *matrix);
int		ft_max(int a, int b);
void	render_background(t_wf *frame);
int		find_max(t_wf *frame);
int		find_min(t_wf *frame);

#endif