/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_freers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:39:12 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/16 16:34:39 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	free_mtx_gnl(t_map *matrix)
{
	free(matrix);
	free(matrix->line);
	gnl_cleaner(matrix->fd);
	close(matrix->fd);
	return (1);
}

int	free_mtx_map_gnl(t_map *matrix, int j)
{
	free_array((void **)matrix->map, j);
	free_triple_pointer(matrix, j);
	gnl_cleaner(matrix->fd);
	free(matrix->line);
	free(matrix);
	close(matrix->fd);
	return (1);
}

int	free_mtx_map(t_map *matrix, int j)
{
	free_array((void **)matrix->map, j);
	free_triple_pointer(matrix, j);
	free(matrix);
	close(matrix->fd);
	return (1);
}
