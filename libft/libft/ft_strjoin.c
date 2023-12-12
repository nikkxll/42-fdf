/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:01:27 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:40:50 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototype: char *ft_strjoin(char const *s1, char const *s2);

// Turn in files: -

// Parameters: s1: The prefix string.
// 			   s2: The suffix string.

// Return value: The new string.
// NULL if the allocation fails.

// External functs.: malloc

// Description: Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*res;
	char	*ret;

	if (!s1 || !s2)
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc((total_len + 1) * sizeof(char));
	if (!res)
		return (0);
	ret = res;
	while (*s1)
	{
		*res = *s1;
		res++;
		s1++;
	}
	while (*s2)
	{
		*res = *s2;
		res++;
		s2++;
	}
	*res = '\0';
	return (ret);
}
