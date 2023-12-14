/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:52 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/14 20:01:28 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	text_runner(int fd, t_map *matrix, char *line, char *buffer)
{
	int		line_count;
	int		bytes;
	char	*newline_pos;
	char	*end;

	line_count = 0;
	bytes = read(fd, buffer, 1000);
	while (bytes > 0)
	{
		if (bytes < 0)
			exit(free_mtx_gnl_buf(buffer, matrix, fd, line));
		newline_pos = buffer;
		end = buffer + bytes;
		newline_pos = ft_memchr(newline_pos, '\n', end - newline_pos);
		while (newline_pos)
		{
			line_count++;
			newline_pos++;
			newline_pos = ft_memchr(newline_pos, '\n', end - newline_pos);
		}
		if (bytes >= 0 && bytes < 1000 && buffer[bytes - 1] != '\n')
			line_count++;
		bytes = read(fd, buffer, 1000);
	}
	return (line_count);
}

static int	count_rows(char **argv, int fd, t_map *matrix, char *line)
{
	int		line_count;
	char	*buffer;

	line_count = 0;
	buffer = (char *)malloc(1000 * sizeof(char));
	if (!buffer)
		exit(free_mtx_gnl(matrix, fd, line));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(free_mtx_gnl_buf(buffer, matrix, fd, line));
	line_count = text_runner(fd, matrix, line, buffer);
	free(buffer);
	if (close(fd) < 0)
		exit(free_mtx_gnl(matrix, fd, line));
	return (line_count);
}

char	*matrix_initializer(t_map *matrix, char **argv, int fd)
{
	char	*line;
	char	**split_line;

	line = get_next_line(fd);
	if (!line)
	{
		free(matrix);
		close(fd);
		exit(1);
	}
	matrix->size_y = count_rows(argv, fd, matrix, line);
	split_line = ft_split(line, ' ');
	if (!split_line)
		exit(free_mtx_gnl(matrix, fd, line));
	matrix->size_x = array_length(split_line);
	matrix->map = (int **)malloc((matrix->size_y) * sizeof(int *));
	if (!matrix->map)
		exit(free_mtx_gnl(matrix, fd, line));
	return (line);
}

t_map	*map_creation(t_map *matrix, int fd, char *line, int j)
{
	char	**temp;
	int		i;

	while (line && *line != '\n')
	{
		i = 0;
		temp = ft_split(line, ' ');
		matrix->map[j] = (int *)malloc(matrix->size_x * sizeof(int));
		if (!matrix->map[j])
		{
			free(line);
			exit(free_mtx_map_tmp_gnl(matrix, temp, fd, j));
		}
		if (atoi_checker(matrix, temp, i, j))
			exit(free_mtx_map_tmp_gnl(matrix, temp, fd, j + 1));
		while (++i - 1 < matrix->size_x)
			matrix->map[j][i - 1] = ft_atoi(temp[i - 1]);
		free_array((void **)temp, matrix->size_x);
		free(line);
		line = get_next_line(fd);
		j++;
		if (line && ((line == NULL && j != matrix->size_y) || line[0] == '\n'))
			exit(free_mtx_map(matrix, j, fd));
	}
	return (matrix);
}
