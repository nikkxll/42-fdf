/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:30:29 by dmitriiniki       #+#    #+#             */
/*   Updated: 2023/12/13 14:15:59 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print(t_map * matrix)
{
    int i = 0;
    int j = 0;

    while(i < matrix->size_y)
    {
        j = 0;
        while(j < matrix->size_x)
        {
            printf("%d ", matrix->map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int main(int argc, char **argv)
{
    t_map	*matrix;
    int fd;
    char *line;
    int i;
    
    i = 0;
    fd = 0;
	if (argc == 2)
    {
        matrix = (t_map *)malloc(sizeof(t_map));
	    if(!matrix)
		    exit(1);
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            free(matrix);
            exit(1);
        }
        line = matrix_initializer(matrix, argv, fd);
        matrix = reader(matrix, argv, fd, line);
        print(matrix);
        free_mem((void **)matrix->map, matrix->size_y);
        free(matrix);
        if (close(fd) < 0)
            exit (1);
    }
}
