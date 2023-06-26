/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:26:33 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/02 17:58:00 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies n bytes from src to dest */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*array;
	char	*s;
	char	*d;

	if (!dest && !src)
		return (NULL);
	array = ft_calloc(n, sizeof(char));
	if (!array)
		return (dest);
	i = -1;
	s = (char *) src;
	while (++i < n)
		array[i] = s[i];
	i = -1;
	d = (char *) dest;
	while (++i < n)
		d[i] = array[i];
	free(array);
	return (dest);
}
