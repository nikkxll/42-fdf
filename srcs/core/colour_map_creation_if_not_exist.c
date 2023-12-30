/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_map_creation_if_not_exist.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:07:38 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/30 16:21:47 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	if_colours_exist(t_wf *frame)
{
	int	i;
	int	j;
	int	colour_flag;

	i = 0;
	j = 0;
	colour_flag = 0;
	while (i < frame->matrix->size_y)
	{
		j = 0;
		while (j < frame->matrix->size_x)
		{
			if (frame->matrix->colmap[i][j])
				colour_flag = 1;
			j++;
		}
		i++;
	}
	return (colour_flag);
}

void	synt_colmap_creation(t_wf *frame)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < frame->matrix->size_y)
	{
		j = 0;
		while (j < frame->matrix->size_x)
		{
			if (frame->matrix->map[i][j] >= 0)
				frame->matrix->colmap[i][j]
					= ft_itoa((int)((float)frame->matrix->map[i][j]
							/ (float)find_max(frame) * 255) << 16);
			else
				frame->matrix->colmap[i][j]
					= ft_itoa((int)((float)frame->matrix->map[i][j]
							/ (float)find_min(frame) * 255));
			j++;
		}
		i++;
	}
}
