/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:24:13 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/14 14:45:49 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	free_mtx_gnl_buf(char *buffer, t_map *matrix, int fd, char *line)
{
	free(matrix);
	free(line);
	gnl_cleaner(fd);
	free(buffer);
	close(fd);
	return (1);
}

int	free_mtx_gnl(t_map *matrix, int fd, char *line)
{
	free(matrix);
	free(line);
	gnl_cleaner(fd);
	close(fd);
	return (1);
}

int	free_mtx_map_tmp_gnl(t_map *matrix, char **temp, int fd, int j)
{
	free_array((void **)matrix->map, j);
	free_array((void **)temp, matrix->size_x);
	gnl_cleaner(fd);
	free(matrix);
	close(fd);
	return (1);
}

int	free_mtx_map(t_map *matrix, int j, int fd)
{
	free_array((void **)matrix->map, j);
	free(matrix);
	close(fd);
	return (1);
}

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
