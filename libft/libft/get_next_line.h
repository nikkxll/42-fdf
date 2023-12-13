/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:53:31 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/13 14:38:57 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);
void	*ft_free(char *str_to_free);
char	*ft_strchr_gnl(const char *s, int c);

#endif