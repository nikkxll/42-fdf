/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:03:12 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:41:12 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototype: char *ft_strtrim(char const *s1, char const *set);

// Turn in files: -

// Parameters: s1: The string to be trimmed.
// 			   set: The reference set of characters to trim.

// Return value: The trimmed string.
// NULL if the allocation fails.

// External functs.: malloc

// Description: Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ re

#include "../libft.h"

static size_t	left_trim_pos(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j] && s1[i] != set[j])
		{
			j++;
		}
		if (!set[j])
		{
			break ;
		}
		i++;
	}
	return (i);
}

static size_t	right_trim_pos(const char *s1, const char *set)
{
	size_t	k;
	size_t	l;

	k = ft_strlen(s1);
	while (k > 0)
	{
		l = 0;
		while (set[l] && s1[k - 1] != set[l])
		{
			l++;
		}
		if (!set[l])
		{
			break ;
		}
		k--;
	}
	return (k);
}

static char	*ft_trim_whole(char *trimmed)
{
	trimmed = (char *)malloc(1);
	if (!trimmed)
		return (NULL);
	trimmed[0] = '\0';
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left_pos;
	size_t	right_pos;
	char	*trimmed;
	size_t	cnt;

	if (!s1)
		return (NULL);
	left_pos = left_trim_pos(s1, set);
	right_pos = right_trim_pos(s1, set);
	if (left_pos > right_pos)
	{
		return (ft_trim_whole(trimmed = NULL));
	}
	trimmed = (char *)malloc(sizeof(char) * (right_pos - left_pos + 1));
	if (!trimmed)
		return (NULL);
	cnt = 0;
	while (left_pos < right_pos)
	{
		trimmed[cnt] = s1[left_pos];
		cnt++;
		left_pos++;
	}
	trimmed[cnt] = '\0';
	return (trimmed);
}
