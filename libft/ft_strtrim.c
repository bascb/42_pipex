/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:35:46 by bcastelo          #+#    #+#             */
/*   Updated: 2022/10/30 15:35:49 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(int c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/* Returns a copy of s1, removing chars in set
	from both ends of s1 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	new_size;
	char	*new;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_is_in_set(s1[i], set))
		i++;
	while (j > 0 && ft_is_in_set(s1[j - 1], set))
		j--;
	if (i >= ft_strlen(s1))
		new_size = 1;
	else
		new_size = j - i + 1;
	new = malloc(new_size * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s1[i], new_size);
	return (new);
}
