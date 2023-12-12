/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:21:11 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:41:03 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototype: char *ft_strmapi(char const *s, char (*f)(unsigned
// int, char));

// Turn in files: -

// Parameters: s: The string on which to iterate.
// 			   f: The function to apply to each character.

// Return value: The string created from the successive applications
// of ’f’.
// Returns NULL if the allocation fails.

// External functs.: malloc

// Description: Applies the function ’f’ to each character of the
// string ’s’, and passing its index as first argument
// to create a new string (with malloc(3)) resulting
// from successive applications of ’f’.

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
