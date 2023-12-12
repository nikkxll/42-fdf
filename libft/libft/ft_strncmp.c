/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:24:51 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:41:05 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <string.h>
//	int strncmp(const char *s1, const char *s2, size_t n);

// DESCRIPTION
//	The strcmp() and strncmp() functions lexicographically compare the 
//	null-terminated strings s1 and s2.

//	The strncmp() function compares not more than n characters.  
//	Because strncmp() is designed for comparing strings
//	rather than binary data, characters that appear after a `\0' character 
//	are not compared.

// RETURN VALUES
//	The strcmp() and strncmp() functions return an integer greater than, 
//	equal to, or less than 0, according as the string s1 is greater than, 
//	equal to, or less than the string s2.  The comparison is done using 
//	unsigned characters, so that `\200' is greater than `\0'.

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
	{
		return (0);
	}
	n--;
	while (*str1 != '\0' && n-- && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
