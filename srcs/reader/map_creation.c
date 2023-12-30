/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:52 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/30 23:29:26 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

char	*matrix_initializer(t_map *matrix, char **argv)
{
	char	**split_line;

	matrix->line = get_next_line(matrix->fd);
	if (!matrix->line || matrix->line[0] == '\n')
	{
		free(matrix);
		close(matrix->fd);
		perror("Empty row in the map or the whole map");
		exit(EXIT_FAILURE);
	}
	matrix->size_y = count_rows(argv, matrix);
	split_line = ft_split(matrix->line, ' ');
	if (!split_line)
		exit(free_mtx_gnl(matrix));
	matrix->size_x = array_length_with_free(split_line);
	if (matrix->size_x == 0)
		exit(free_mtx_gnl(matrix));
	matrix->map = (int **)malloc((matrix->size_y) * sizeof(int *));
	if (!matrix->map)
		exit(free_mtx_gnl(matrix));
	matrix->colmap = (char ***)malloc((matrix->size_y) * sizeof(char **));
	if (!matrix->colmap)
		exit(free_mtx_map_gnl(matrix, 0));
	return (matrix->line);
}

static void	map_creation_checkers(char **temp, t_map *matrix, int j, int i)
{
	if (!temp)
		exit(free_mtx_map_gnl(matrix, j));
	if (array_length(temp) != matrix->size_x)
		exit(free_mtx_map_tmp_gnl(matrix, temp, j, j));
	matrix->map[j] = (int *)malloc(matrix->size_x * sizeof(int));
	if (!matrix->map[j])
		exit(free_mtx_map_tmp_gnl(matrix, temp, j, j));
	matrix->colmap[j] = (char **)malloc(matrix->size_x * sizeof(char *));
	if (!matrix->colmap[j])
		exit(free_mtx_map_tmp_gnl(matrix, temp, j + 1, j));
	colour_extractor(temp, matrix, j);
	if (atoi_checker(matrix, temp, i, j))
		exit(free_mtx_map_tmp_gnl(matrix, temp, j + 1, j + 1));
}

t_map	*map_creation(t_map *matrix, int j, int i)
{
	char	**temp;

	while (matrix->line && *matrix->line != '\n')
	{
		i = 0;
		temp = ft_split(matrix->line, ' ');
		map_creation_checkers(temp, matrix, j, i);
		while (++i - 1 < matrix->size_x)
			matrix->map[j][i - 1] = ft_atoi(temp[i - 1]);
		free_split(temp);
		free(matrix->line);
		matrix->line = get_next_line(matrix->fd);
		j++;
		if (matrix->line && ((matrix->line == NULL
					&& j != matrix->size_y) || matrix->line[0] == '\n'))
			exit(free_mtx_map(matrix, j));
	}
	return (matrix);
}
