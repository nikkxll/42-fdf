/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:23:10 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:41:10 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <string.h>
//	char *strrchr(const char *s, int c);

// DESCRIPTION
//	The strchr() function locates the first occurrence of c (converted to a 
//	char) in the string pointed to by s.  The terminating null character is 
//	considered to be part of the string; therefore if c is `\0', the 
//	functions locate the terminating `\0'.

//	The strrchr() function is identical to strchr(), except it locates the 
//	last occurrence of c.

// RETURN VALUES
//	The functions strchr() and strrchr() return a pointer to the located 
//	character, or NULL if the character does not appear in the string.

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	j;
	char	*r;

	i = 0;
	j = 0;
	r = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			r = (char *)(s + i);
			j++;
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	if (j == 0)
		return (NULL);
	return (r);
}
