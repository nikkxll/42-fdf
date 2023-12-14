/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:46:44 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/14 23:50:06 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print(t_map *matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < matrix->size_y)
	{
		j = 0;
		while (j < matrix->size_x)
		{
			printf("%d ", matrix->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

t_map	*reader(char **argv)
{
	t_map	*matrix;

	matrix = (t_map *)malloc(sizeof(t_map));
	matrix->fd = open(argv[1], O_RDONLY);
	if (matrix->fd == -1)
	{
		free(matrix);
		exit(1);
	}
	matrix->line = matrix_initializer(matrix, argv);
	matrix = map_creation(matrix, 0, 0);
	if (close(matrix->fd) < 0)
		exit(free_mtx_map(matrix, matrix->size_y));
	return (matrix);
}
