/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixed_freers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:24:13 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/16 16:34:42 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	free_array(void **arr, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_triple_pointer(t_map *matrix, int length)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	while (i < length)
	{
		k = 0;
		while (k < matrix->size_x)
		{
			free(matrix->colmap[i][k]);
			k++;
		}
		free(matrix->colmap[i]);
		i++;
	}
	free(matrix->colmap);
}

int	free_mtx_gnl_buf(char *buffer, t_map *matrix)
{
	free(matrix);
	free(matrix->line);
	gnl_cleaner(matrix->fd);
	free(buffer);
	close(matrix->fd);
	return (1);
}

int	free_mtx_map_tmp_gnl(t_map *matrix, char **temp, int j, int i)
{
	free_array((void **)matrix->map, j);
	free_triple_pointer(matrix, i);
	free_array((void **)temp, array_length(temp));
	gnl_cleaner(matrix->fd);
	free(matrix->line);
	free(matrix);
	close(matrix->fd);
	return (1);
}
