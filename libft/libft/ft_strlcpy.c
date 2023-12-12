/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:13:09 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:40:59 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <string.h>
//	size_t strlcpy(char * restrict dst, const char * restrict src, 
//	size_t dstsize);

// DESCRIPTION
//	The strlcpy() and strlcat() functions copy and concatenate strings with 
//	the same input parameters and output result as snprintf(3).  They are 
//	designed to be safer, more consistent, and less error prone replacements 
//	for the easily misused functions strncpy(3) and strncat(3).

//	strlcpy() and strlcat() take the full size of the destination buffer 
//	and guarantee NUL-termination if there is room.
//	Note that room for the NUL should be included in dstsize.

//	strlcpy() copies up to dstsize - 1 characters from the string src to 
//	dst, NUL-terminating the result if dstsize is not 0.

//	If the src and dst strings overlap, the behavior is undefined.

// RETURN VALUES
//	Besides quibbles over the return type (size_t versus int) and signal 
//	handler safety (snprintf(3) is not entirely safe
//	on some systems), the following two are equivalent:

//	n = strlcpy(dst, src, len);
//	n = snprintf(dst, len, "%s", src);

//	Like snprintf(3), the strlcpy() and strlcat() functions return the 
//	total length of the string they tried to create. For strlcpy() 
//	that means the length of src.  For strlcat() that means the initial 
//	length of dst plus the length of src.

//	If the return value is >= dstsize, the output string has been truncated.
//	It is the caller's responsibility to handle this.

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	while (src[i] != '\0')
	{
		if (dstsize && (i < (dstsize - 1)))
		{
			dst[i] = src[i];
			j++;
		}
		i++;
	}
	dst[j] = '\0';
	return (i);
}
