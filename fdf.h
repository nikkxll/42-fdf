/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:12:10 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/14 00:23:09 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./libft/libft/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	int	size_y;
	int	size_x;
	int	**map;
}	t_map;

t_map	*map_creation(t_map *matrix, int fd, char *line);
char	*matrix_initializer(t_map *matrix, char **argv, int fd);

int		free_mtx_gnl_buf(char *buffer, t_map *matrix, int fd, char *line);
int		free_mtx_gnl(t_map *matrix, int fd, char *line);
int		free_mtx_map_tmp_gnl(t_map *matrix, char **temp, int fd, int j);
int		free_mtx_map(t_map *matrix, int j);
void	free_array(void **arr, int length);

void	gnl_cleaner(int fd);

#endif