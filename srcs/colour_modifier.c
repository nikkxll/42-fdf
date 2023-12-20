/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:05:05 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/20 12:17:04 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	select_hex_mode(char *arg)
{
	size_t	low;
	size_t	cap;
	size_t	i;

	low = 0;
	cap = 0;
	i = 0;
	while (arg[i])
	{
		if (ft_strchr("ABCDEF", arg[i]))
			cap++;
		else if (ft_strchr("abcdef", arg[i]))
			low++;
		if (low != 0 && cap != 0)
			return (-1);
		i++;
	}
	return (1 * (low != 0));
}

long	ft_atoi_base(char *num, int format)
{
	size_t		pos;
	long		result;
	char const	*charset;

	if (format == 0)
		charset = "0123456789ABCDEF";
	else
		charset = "0123456789abcdef";
	pos = 0;
	result = 0;
	while (*num)
	{
		while (*num != charset[pos])
			pos++;
		result = result * 16 + pos;
		pos = 0;
		num++;
	}
	return (result);
}

long	colour_modifier(t_map *matrix, int i, int j)
{
	long			number;
	int				mode;

	if (!matrix->colmap[i][j])
		number = 16777215;
	else if (matrix->colmap[i][j][0] == '0' && matrix->colmap[i][j][1] == 'x')
	{
		mode = select_hex_mode(matrix->colmap[i][j] + 2);
		if (mode == -1)
			exit(1);
		number = ft_atoi_base(matrix->colmap[i][j] + 2, mode);
		if (number > 0xFFFFFF || number < 0)
			exit(1);
	}
	else
	{
		if (null_checker(matrix->colmap[i][j], 0, 0))
			exit(1);
		number = ft_atoi(matrix->colmap[i][j]);
		if (number > 0xFFFFFF || number < 0)
			exit(1);
	}
	number = (number << 8) | 0xff;
	return (number);
}
