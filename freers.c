/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:24:13 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/13 20:59:37 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_set_one(char *buffer, t_map *matrix, int fd, char *line)
{
	free(matrix);
	free(line);
	gnl_cleaner(fd);
	free(buffer);
	return (1);
}

int	free_set_two(t_map *matrix, int fd, char *line)
{
	free(matrix);
	free(line);
	gnl_cleaner(fd);
	return (1);
}

int	free_set_three(t_map *matrix, char **temp, int fd, int j)
{
	free_mem((void **)matrix->map, j);
	free_mem((void **)temp, matrix->size_x);
	gnl_cleaner(fd);
	free(matrix);
	return (1);
}

int	free_set_four(t_map *matrix, int j)
{
	free_mem((void **)matrix->map, j);
	free(matrix);
	return (1);
}

void	free_mem(void **arr, int length)
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
