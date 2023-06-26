/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 08:32:58 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/12 08:33:07 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putdigit(char *str, char c)
{
	size_t	i;

	i = ft_strlen(str);
	str[i] = c;
}

static void	ft_utoa_r(unsigned int n, char *number)
{
	if (n > 9)
		ft_utoa_r(n / 10, number);
	ft_putdigit(number, n % 10 + '0');
}

static char	*ft_custom_str(char *number)
{
	char	*new;

	new = ft_strdup(number);
	if (!new)
		return (number);
	free(number);
	return (new);
}

/* Returns a string representing the unsigned integer n */
char	*ft_utoa(int n)
{
	char	*number;

	number = ft_calloc(20, sizeof(char));
	if (!number)
		return (NULL);
	ft_utoa_r(n, number);
	return (ft_custom_str(number));
}
