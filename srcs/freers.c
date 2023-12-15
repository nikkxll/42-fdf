/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:24:13 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/15 13:35:02 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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

int	free_mtx_gnl_buf(char *buffer, t_map *matrix)
{
	free(matrix);
	free(matrix->line);
	gnl_cleaner(matrix->fd);
	free(buffer);
	close(matrix->fd);
	return (1);
}

int	free_mtx_gnl(t_map *matrix)
{
	free(matrix);
	free(matrix->line);
	gnl_cleaner(matrix->fd);
	close(matrix->fd);
	return (1);
}

int	free_mtx_map_tmp_gnl(t_map *matrix, char **temp, int j)
{
	free_array((void **)matrix->map, j);
	free_array((void **)temp, array_length(temp));
	gnl_cleaner(matrix->fd);
	free(matrix->line);
	free(matrix);
	close(matrix->fd);
	return (1);
}

int	free_mtx_map(t_map *matrix, int j)
{
	free_array((void **)matrix->map, j);
	free(matrix);
	close(matrix->fd);
	return (1);
}
