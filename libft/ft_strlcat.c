/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:00:14 by bcastelo          #+#    #+#             */
/*   Updated: 2022/10/27 13:17:33 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* concatenates src to dest in a safe mode */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len >= size)
		return (size + src_len);
	i = 0;
	while (i + dest_len + 1 < size && src[i])
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	if (i < size)
		dest[i + dest_len] = '\0';
	return (dest_len + src_len);
}
