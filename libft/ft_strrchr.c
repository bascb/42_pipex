/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:32:22 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/02 22:59:49 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns a pointer to the last occurence 
   of char c in string str */
char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*last;

	last = NULL;
	i = 0;
	if (c > 255)
		c = c % 256;
	while (str[i])
	{
		if (str[i] == (char) c)
			last = (char *) &str[i];
		i++;
	}
	if (c == '\0')
		last = (char *) &str[i];
	return (last);
}
