/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:38:27 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:40:45 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <string.h>
//	char *strdup(const char *s1);

// DESCRIPTION
//	The strdup() function allocates sufficient memory for a copy of the 
//	string s1, does the copy, and returns a pointer to it.  
//	The pointer may subsequently be used as an argument to the 
//	function free(3).

//	If insufficient memory is available, NULL is returned 
//	and errno is set to ENOMEM.

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*ptr;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	ptr = dest;
	while (*s1 != '\0')
	{
		*dest = *s1;
		dest++;
		s1++;
	}
	*dest = '\0';
	return (ptr);
}
