/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:34:16 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/13 19:43:49 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
