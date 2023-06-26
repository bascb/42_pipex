/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:50:09 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/02 19:17:07 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_strings(char const *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] != c)
			count++;
		if (str[i] == c && str[i + 1] && str[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_alloc_array(char const *s, char c)
{
	char	**strings;	
	size_t	strings_number;

	strings_number = ft_count_strings(s, c);
	strings = malloc((strings_number + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	strings[strings_number] = NULL;
	return (strings);
}

static	char	**ft_customize_array(char **strings)
{
	char	*new;
	int		i;

	i = 0;
	while (strings[i])
	{
		new = ft_strdup(strings[i]);
		free(strings[i]);
		strings[i] = new;
		i++;
	}
	return (strings);
}

/* Returns an array of strings obtained by
	by splitting 's' using the char 'c' 
	as delimiter */
char	**ft_split(char const *s, char c)
{
	char	**strings;	
	size_t	j;
	size_t	m;

	strings = ft_alloc_array(s, c);
	if (!strings)
		return (NULL);
	j = 0;
	m = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (!j && !m)
			strings[j] = ft_calloc(ft_strlen(s) + 1, sizeof(char));
		if (*s == c && *(s + 1) && *(s + 1) != c)
		{
			strings[++j] = ft_calloc(ft_strlen(s) + 1, sizeof(char));
			m = 0;
		}
		else if (*s != c)
			strings[j][m++] = *s;
		s++;
	}
	return (ft_customize_array(strings));
}
