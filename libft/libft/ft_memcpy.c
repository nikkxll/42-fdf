/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:52:09 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:40:11 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <string.h>
//	void *memcpy(void *restrict dst, const void *restrict src, size_t n);

// DESCRIPTION
//	The memcpy() function copies n bytes from memory area src to memory 
//	area dst.  If dst and src overlap, behavior is undefined.  
//	Applications in which dst and src might overlap should use 
//	memmove(3) instead.

// RETURN VALUES
//	The memcpy() function returns the original value of dst.

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
