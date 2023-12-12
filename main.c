/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:52 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/12 15:06:42 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int array_length(char **arr)
{
	int length;

	length = 0;
	while (arr[length] != NULL)
		length++;
	return (length);
}

// int count_lines(int fd)
// {
// 	char	*line;
// 	int		lines;

// 	lines = 0;
// 	while (line && *line != '\n')
// 	{
// 		line = get_next_line(fd);
// 		if (line && *line != '\n')
// 			lines++;
// 	}
// 	return (lines);
// }

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	**temp;
	int		i;
	int		j;
	int		length;
	int		**result;
	
	result = (int **)malloc(100 * sizeof(int *));
	if (argc == 2)
	{
		i = 0;
		j = 0;
		fd = open(argv[1], O_RDONLY);
		line = get_next_line(fd);
		while (line && *line != '\n')
		{
			temp = ft_split(line, ' ');
			length = array_length(temp);
			result[j] = (int *)malloc(length * sizeof(int));
			while (i < length)
			{
				result[j][i] = ft_atoi(temp[i]);
				i++;
			}
			j++;
			line = get_next_line(fd);
		}
		for (i = 0; i < length; i++)
			printf("%d", result[1][i]);
	}
}
