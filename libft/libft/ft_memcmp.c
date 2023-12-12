/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:27:32 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:40:06 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <string.h>
//	int memcmp(const void *s1, const void *s2, size_t n);

// DESCRIPTION
//	The memcmp() function compares byte string s1 against byte string s2.  
//	Both strings are assumed to be n bytes long.

// RETURN VALUES
//	The memcmp() function returns zero if the two strings are identical, 
//	otherwise returns the difference between the first two differing bytes 
//	(treated as unsigned char values, so that `\200' is greater than `\0', 
//	for example).  Zero-length strings are always identical.  
//	This behavior is not required by C and portable code should only 
//	depend on the sign of the returned value.

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}
