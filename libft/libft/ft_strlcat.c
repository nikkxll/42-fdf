/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:17:17 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:40:52 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <string.h>

//	size_t strlcat(char * restrict dst, const char * restrict src, 
//	size_t dstsize);

// DESCRIPTION
//	The strlcpy() and strlcat() functions copy and concatenate strings 
//	with the same input parameters and output result as snprintf(3).  
//	They are designed to be safer, more consistent, and less error prone 
//	replacements for the easily misused functions strncpy(3) and strncat(3).

//	strlcpy() and strlcat() take the full size of the destination buffer 
//	and guarantee NUL-termination if there is room. Note that room for 
//	the NUL should be included in dstsize.

//	strlcat() appends string src to the end of dst.  It will append at most 
//	dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, 
//	unless dstsize is 0 or the original dst string was longer than dstsize 
//	(in practice this should not happen as it means that either dstsize is 
//	incorrect or that dst is not a proper string).

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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	j = 0;
	tmp = dst;
	src_len = ft_strlen(src);
	if (dstsize == 0 && !dst)
		return (dstsize + src_len);
	dest_len = ft_strlen(dst);
	if (ft_strlen(dst) >= dstsize)
		return (dstsize + src_len);
	while (tmp[i] != '\0')
		i++;
	while (j < src_len && (j < (dstsize - dest_len - 1)))
	{
		tmp[i] = src[j];
		j++;
		i++;
	}
	tmp[i] = '\0';
	return (dest_len + src_len);
}
