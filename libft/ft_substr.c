/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:31:08 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/02 22:54:55 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Creates a new string with a copy from start to, at most len */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	new_len;

	if ((size_t) start >= ft_strlen(s))
	{
		new_len = 1;
		start = (unsigned int) ft_strlen(s);
	}
	else if (len > ft_strlen(s) - (size_t) start)
		new_len = ft_strlen(s) - (size_t) start + 1;
	else
		new_len = len + 1;
	new = malloc(new_len * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s[start], new_len);
	return (new);
}
