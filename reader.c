/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:52 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/13 01:05:10 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mem(char **arr)
{
	int length;
	int	i;

	length = 0;
	i = 0;
	while (arr[length] != NULL)
		length++;
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
	free_mem(arr);
	return (length);
}

int count_rows(char **argv, int fd)
{
    int		line_count;
    char	*buffer;
    int		bytes_read;
    char	*newline_pos;

	line_count = 0;
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (-1);
	fd = open(argv[1], O_RDONLY);
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
        newline_pos = buffer;
        char *end = buffer + bytes_read;
        while ((newline_pos = ft_memchr(newline_pos, '\n', end - newline_pos)))
		{
            line_count++;
            newline_pos++;
        }
    }
    free(buffer);
	close(fd);
	return (line_count + 1);
}

char	*matrix_initializer(t_map	*matrix, char **argv, int fd)
{
	char *line;

	line = get_next_line(fd);
	matrix->size_y = count_rows(argv, fd);
	matrix->size_x = array_length(ft_split(line, ' '));
	matrix->map = (int **)malloc((matrix->size_y) * sizeof(int *));
	return (line);
}

t_map *reader(t_map	*matrix, char **argv, int fd, char *line)
{
	char	**temp;
	int		i;
	int		j;
	
	j = 0;
	while (line && *line != '\n')
	{
		i = 0;
		temp = ft_split(line, ' ');
		matrix->map[j] = (int *)malloc(matrix->size_x * sizeof(int));
		while (i < matrix->size_x)
		{
			matrix->map[j][i] = ft_atoi(temp[i]);
			i++;
		}
		free_mem(temp);
		j++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (matrix);
}
