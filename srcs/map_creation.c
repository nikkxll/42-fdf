/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:52 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/14 23:56:39 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*matrix_initializer(t_map *matrix, char **argv)
{
	char	**split_line;

	matrix->line = get_next_line(matrix->fd);
	if (!matrix->line)
	{
		free(matrix);
		close(matrix->fd);
		exit(1);
	}
	matrix->size_y = count_rows(argv, matrix);
	split_line = ft_split(matrix->line, ' ');
	if (!split_line)
		exit(free_mtx_gnl(matrix));
	matrix->size_x = array_length(split_line);
	matrix->map = (int **)malloc((matrix->size_y) * sizeof(int *));
	if (!matrix->map)
		exit(free_mtx_gnl(matrix));
	return (matrix->line);
}

t_map	*map_creation(t_map *matrix, int j, int i)
{
	char	**temp;

	while (matrix->line && *matrix->line != '\n')
	{
		i = 0;
		temp = ft_split(matrix->line, ' ');
		matrix->map[j] = (int *)malloc(matrix->size_x * sizeof(int));
		if (!matrix->map[j])
			exit(free_mtx_map_tmp_gnl(matrix, temp, j));
		if (atoi_checker(matrix, temp, i, j))
			exit(free_mtx_map_tmp_gnl(matrix, temp, j + 1));
		while (i < matrix->size_x)
		{
			matrix->map[j][i] = ft_atoi(temp[i]);
			i++;
		}
		free_array((void **)temp, matrix->size_x);
		free(matrix->line);
		matrix->line = get_next_line(matrix->fd);
		j++;
		if (matrix->line && ((matrix->line == NULL && j != matrix->size_y) || matrix->line[0] == '\n'))
			exit(free_mtx_map(matrix, j));
	}
	return (matrix);
}
