/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:39:05 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/02 21:06:21 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* locates the first occurence  of s2 in s1 
	returns s2 if s2 exists, NULL if not and
	s1 if n is 0 */
char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*main;
	const char	*sub;
	size_t		count;

	if ((!ft_strlen(s2)))
		return ((char *) s1);
	while (*s1 && n)
	{
		main = s1;
		sub = s2;
		count = n;
		while (*main && *main == *sub && count)
		{
			main++;
			sub++;
			count--;
		}
		if (!*sub)
			return ((char *) s1);
		s1++;
		n--;
	}
	return (NULL);
}
