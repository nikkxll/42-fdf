/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:30:29 by dmitriiniki       #+#    #+#             */
/*   Updated: 2023/12/13 01:10:00 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    t_map	*matrix;
    int fd;
    char *line;
    int i;
    
    i = 0;
	if (argc == 2)
    {
        matrix = (t_map *)malloc(sizeof(t_map));
	    if(!matrix)
		    return (0);
        fd = open(argv[1], O_RDONLY);
        line = matrix_initializer(matrix, argv, fd);
        matrix = reader(matrix, argv, fd, line);
        close(fd);
    }
    while (i < matrix->size_y)
    {
        free(matrix->map[i]);
        i++;
    }
    free(matrix->map);
    free(matrix);
}
