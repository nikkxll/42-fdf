/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:55:38 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/14 23:58:47 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	text_runner(int first_read_fd, t_map *matrix, char *buffer)
{
	int		line_count;
	int		bytes;
	char	*newline_pos;
	char	*end;

	line_count = 0;
	bytes = read(first_read_fd, buffer, 1000);
	while (bytes > 0)
	{
		if (bytes < 0)
			exit(free_mtx_gnl_buf(buffer, matrix));
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
		bytes = read(first_read_fd, buffer, 1000);
	}
	return (line_count);
}

int	count_rows(char **argv, t_map *matrix)
{
	int		line_count;
	char	*buffer;
	int		first_read_fd;
	
	line_count = 0;
	buffer = (char *)malloc(1000 * sizeof(char));
	if (!buffer)
		exit(free_mtx_gnl(matrix));
	first_read_fd = open(argv[1], O_RDONLY);
	if (first_read_fd < 0)
		exit(free_mtx_gnl_buf(buffer, matrix));
	line_count = text_runner(first_read_fd, matrix, buffer);
	free(buffer);
	if (close(first_read_fd) < 0)
		exit(free_mtx_gnl(matrix));
	return (line_count);
}
