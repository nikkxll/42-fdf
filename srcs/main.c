/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:17:57 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/14 00:43:52 by dmitriiniki      ###   ########.fr       */
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

t_map	*reader(t_map *matrix, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free(matrix);
		exit(1);
	}
	line = matrix_initializer(matrix, argv, fd);
	matrix = map_creation(matrix, fd, line);
	if (close(fd) < 0)
		exit(free_mtx_map(matrix, matrix->size_y));
	return (matrix);
}

int	main(int argc, char **argv)
{
	t_map	*matrix;

	matrix = (t_map *)malloc(sizeof(t_map));
	if (!matrix)
		exit(1);
	if (argc == 2)
	{
		matrix = reader(matrix, argv);
		print(matrix);
		free_mtx_map(matrix, matrix->size_y);
	}
}
