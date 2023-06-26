/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:01:32 by bcastelo          #+#    #+#             */
/*   Updated: 2022/10/30 14:01:37 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Join s1 with s2 and returns a pointer to the new string */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	new_len;

	new_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(new_len * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, new_len);
	ft_strlcat(new, s2, new_len);
	return (new);
}
