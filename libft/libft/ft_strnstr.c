/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:29:55 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:41:08 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <string.h>
//	char *strnstr(const char *haystack, const char *needle, size_t len);

// DESCRIPTION
//	The strnstr() function locates the first occurrence of the 
//	null-terminated string needle in the string haystack, where not more than
//	len characters are searched.  Characters that appear after a `\0' 
//	character are not searched.
//	Since the strnstr() function is a FreeBSD specific API, it should only 
//	be used when portability is not a concern.

// RETURN VALUES
//	If needle is an empty string, haystack is returned; if needle occurs 
//	nowhere in haystack, NULL is returned; otherwise a pointer to the first 
//	character of the first occurrence of needle is returned.

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*start;
	const char	*temp_little;
	size_t		count;

	count = len;
	if (*needle == 0 || ((char *)haystack == 0 && len == 0))
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		start = haystack;
		temp_little = needle;
		len = count;
		while (*haystack == *temp_little && *haystack && len > 0)
		{
			haystack++;
			temp_little++;
			len--;
		}
		if (*temp_little == '\0')
			return ((char *)start);
		haystack = start + 1;
		count--;
	}
	return (NULL);
}
