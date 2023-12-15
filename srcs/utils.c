/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:34:16 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/15 12:04:32 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	gnl_cleaner(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && *line != '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

int	array_length_with_free(char **split_line)
{
	int	length;

	length = 0;
	while (split_line[length] != NULL)
	{
		if (split_line[length][0] == '\n')
		{
			free(split_line[length]);
			split_line[length] = NULL;
			free_array((void **)split_line, length);
			return (length);
		}
		length++;
	}
	free_array((void **)split_line, length);
	return (length);
}

int	array_length(char **split_line)
{
	int	length;

	length = 0;
	while (split_line[length] != NULL
		&& ft_strncmp(split_line[length], "\n", 1) != 0)
		length++;
	return (length);
}
