/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:20:33 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:38:45 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <strings.h>
//	void bzero(void *s, size_t n);

// DESCRIPTION
//	The bzero() function writes n zeroed bytes to the string s.  
//	If n is zero, bzero() does nothing.

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
