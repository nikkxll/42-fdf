/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:46:44 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/14 20:01:37 by dnikifor         ###   ########.fr       */
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
	int		fd;
	char	*line;
	t_map	*matrix;

	matrix = (t_map *)malloc(sizeof(t_map));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free(matrix);
		exit(1);
	}
	line = matrix_initializer(matrix, argv, fd);
	matrix = map_creation(matrix, fd, line, 0);
	if (close(fd) < 0)
		exit(free_mtx_map(matrix, matrix->size_y, fd));
	return (matrix);
}
