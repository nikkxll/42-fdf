/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:16:52 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:39:37 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototype: char *ft_itoa(int n);

// Turn in files: -

// Parameters: n: the integer to convert.

// Return value: The string representing the integer.
// NULL if the allocation fails.

// External functs.: malloc

// Description: Allocates (with malloc(3)) and returns a string
// representing the integer received as an argument.
// Negative numbers must be handled.

#include "../libft.h"

static void	ft_char_cpy(char *dest, char src, int *position)
{
	dest[(*position)++] = src;
}

static int	ft_num_len(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	ft_str_extractor(char *str, int nb, int *position)
{
	if (nb < 0)
	{
		ft_char_cpy(str, '-', position);
		nb = -nb;
	}
	if (nb < 10)
	{
		ft_char_cpy(str, nb + '0', position);
	}
	else
	{
		ft_str_extractor(str, nb / 10, position);
		ft_char_cpy(str, (nb % 10) + '0', position);
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		position;

	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	len = ft_num_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	position = 0;
	ft_str_extractor(str, n, &position);
	str[position] = '\0';
	return (str);
}
