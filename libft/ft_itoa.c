/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:50:15 by bcastelo          #+#    #+#             */
/*   Updated: 2022/11/02 19:27:28 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putdigit(char *str, char c)
{
	size_t	i;

	i = ft_strlen(str);
	str[i] = c;
}

static void	ft_itoa_r(unsigned int n, char *number)
{
	if (n > 9)
		ft_itoa_r(n / 10, number);
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

/* Returns a string representing the integer n */
char	*ft_itoa(int n)
{
	char	*number;

	number = ft_calloc(20, sizeof(char));
	if (!number)
		return (NULL);
	if (n < 0)
	{
		ft_putdigit(number, '-');
		ft_itoa_r(-n, number);
	}
	else
		ft_itoa_r(n, number);
	return (ft_custom_str(number));
}
