/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:34:16 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/16 16:44:23 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

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

char	*ft_strdup_nl(const char *s1)
{
	char	*dest;
	char	*ptr;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	ptr = dest;
	while (*s1 != '\0' && *s1 != '\n')
	{
		*dest = *s1;
		dest++;
		s1++;
	}
	*dest = '\0';
	return (ptr);
}
