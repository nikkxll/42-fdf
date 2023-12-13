/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:12:10 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/13 21:01:03 by dnikifor         ###   ########.fr       */
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

t_map	*reader(t_map	*matrix, char **argv, int fd, char *line);
char	*matrix_initializer(t_map *matrix, char **argv, int fd);

int		free_set_one(char *buffer, t_map *matrix, int fd, char *line);
int		free_set_two(t_map *matrix, int fd, char *line);
int		free_set_three(t_map *matrix, char **temp, int fd, int j);
int		free_set_four(t_map *matrix, int j);
void	free_mem(void **arr, int length);

void	gnl_cleaner(int fd);

#endif