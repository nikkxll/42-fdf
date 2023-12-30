/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:01:37 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/30 16:56:45 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	render_background(t_wf *frame)
{
	int	i;
	int	j;

	if (frame->img == NULL)
		return ;
	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
			mlx_put_pixel(frame->img, j++, i, 0x000000ff);
		++i;
	}
}

int	find_max(t_wf *frame)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = -2147483648;
	while (i < frame->matrix->size_y)
	{
		j = 0;
		while (j < frame->matrix->size_x)
		{
			if (frame->matrix->map[i][j] > max)
				max = frame->matrix->map[i][j];
			j++;
		}
		i++;
	}
	return (max);
}

int	find_min(t_wf *frame)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	min = 2147483647;
	while (i < frame->matrix->size_y)
	{
		j = 0;
		while (j < frame->matrix->size_x)
		{
			if (frame->matrix->map[i][j] < min)
				min = frame->matrix->map[i][j];
			j++;
		}
		i++;
	}
	return (min);
}
