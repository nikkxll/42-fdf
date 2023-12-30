/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:46:44 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/30 21:19:18 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

t_map	*reader(char **argv)
{
	t_map	*matrix;

	matrix = (t_map *)malloc(sizeof(t_map));
	matrix->fd = open(argv[1], O_RDONLY);
	if (matrix->fd == -1)
	{
		free(matrix);
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	matrix->line = matrix_initializer(matrix, argv);
	matrix = map_creation(matrix, 0, 0);
	if (close(matrix->fd) < 0)
		exit(free_mtx_map(matrix, matrix->size_y));
	return (matrix);
}
