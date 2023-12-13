/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:52 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/13 14:53:57 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int array_length(char **arr)
{
	int length;
	int	i;

	length = 0;
	i = 0;
	while (arr[length] != NULL)
		length++;
	free_mem((void **)arr, length);
	return (length);
}

int count_rows(char **argv, int fd, t_map	*matrix, char *line)
{
    int		line_count;
    char	*buffer;
    int		bytes_read;
    char	*newline_pos;

	line_count = 0;
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
	{
		free(matrix);
		free(line);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		free(matrix);
		free(line);
		free(buffer);
		exit(1);
	}
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (bytes_read < 0)
		{
			free(matrix);
			free(line);
			free(buffer);
			exit(1);
		}
        newline_pos = buffer;
        char *end = buffer + bytes_read;
        while ((newline_pos = ft_memchr(newline_pos, '\n', end - newline_pos)))
		{
            line_count++;
            newline_pos++;
        }
    }
    free(buffer);
	if (close(fd) < 0)
	{
		free(matrix);
		free(line);
		exit(1);
	}
	return (line_count);
}

char	*matrix_initializer(t_map	*matrix, char **argv, int fd)
{
	char *line;
	char **split_line;

	line = get_next_line(fd);
	if (!line)
	{
		free(matrix);
		exit(1);
	}
	matrix->size_y = count_rows(argv, fd, matrix, line);
	split_line = ft_split(line, ' ');
	if (!split_line)
	{
		free(matrix);
		free(line);
		exit(1);
	}
	matrix->size_x = array_length(split_line);
	matrix->map = (int **)malloc((matrix->size_y) * sizeof(int *));
	if (!matrix->map)
	{
		free(matrix);
		free(line);
		exit(1);
	}
	return (line);
}

t_map *reader(t_map	*matrix, char **argv, int fd, char *line)
{
	char	**temp;
	int		i;
	int		j;
	int		k;
	
	j = 0;
	k = 0;
	while (line && *line != '\n')
	{
		i = 0;
		temp = ft_split(line, ' ');
		matrix->map[j] = (int *)malloc(matrix->size_x * sizeof(int));
		if (!matrix->map[j])
		{
			free_mem((void **)matrix->map, j);
			free_mem((void **)temp, matrix->size_x);
			free(line);
			free(matrix);
			exit(1);
		}
		while (i < matrix->size_x)
		{
			matrix->map[j][i] = ft_atoi(temp[i]);
			i++;
		}
		free_mem((void **)temp, matrix->size_x);
		free(line);
		j++;
		line = get_next_line(fd);
		if (line == NULL && j != matrix->size_y)
		{
			free_mem((void **)matrix->map, j);
			free(matrix);
			exit (1);
		}
	}
	return (matrix);
}
