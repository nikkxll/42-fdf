/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:15:57 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:40:41 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototype: char **ft_split(char const *s, char c);

// Turn in files: -

// Parameters: s: The string to be split.
// 			   c: The delimiter character.

// Return value: The array of new strings resulting from the split.
// NULL if the allocation fails.

// External functs.: malloc, free

// Description: Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// character ’c’ as a delimiter. The array must end
// with a NULL pointer.

#include "../libft.h"

static int	char_is_separator(char ch, char c)
{
	if (ch == c)
		return (1);
	if (ch == '\0')
		return (1);
	return (0);
}

static void	write_word(char *dest, char const *from, char c)
{
	int	i;

	i = 0;
	while (char_is_separator(from[i], c) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static void	free_mem(char **split, int word)
{
	int	i;

	i = 0;
	while (i < word)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	write_split(char **split, char const *str, char c, int i)
{
	int	j;
	int	word;

	word = 0;
	while (str[i] != '\0')
	{
		if (char_is_separator(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (char_is_separator(str[i + j], c) == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!split[word])
			{
				free_mem(split, word);
				return (1);
			}
			write_word(split[word], str + i, c);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;

	words = 0;
	i = 0;
	if (!s)
	{
		return (0);
	}
	while (s[i] != '\0')
	{
		if (char_is_separator(s[i + 1], c) == 1
			&& char_is_separator(s[i], c) == 0)
			words++;
		i++;
	}
	i = 0;
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	if (write_split(res, s, c, i) == 1)
		return (NULL);
	res[words] = NULL;
	return (res);
}
